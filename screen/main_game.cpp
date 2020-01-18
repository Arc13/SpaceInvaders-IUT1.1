#include "main_game.h"

#include <fstream>
#include <iostream>

#include "../game/manager.h"
#include "../game/manager_const.h"

#include "../graph/rgbacolor.h"
#include "../graph/vec2d.h"

#define GAME nsScreen::MainGame

GAME::MainGame()
    : m_difficulty(nsGame::KNormalDifficulty)
    , m_deplacementEnnemi(std::chrono::microseconds::zero())
    , m_tir(std::chrono::microseconds::zero())
    , m_missile(std::chrono::microseconds::zero())
    , m_freqDeplacementEnnemi (3000)
    , m_freqTir (1500)
    , m_freqMissile (100)
    , m_ennemiDeplacementDroite(true)
    , m_vies(m_difficulty.lifeCount)
    , m_texteViesTitre(Vec2D(5, 0), "Vies", RGBAcolor(128, 128, 128),
                       GlutFont::BITMAP_8_BY_13, nsGui::Text::ALIGNV_TOP)
    , m_texteVies(Vec2D(5, 15), std::to_string(m_vies), RGBAcolor(192, 192, 192),
                  GlutFont::BITMAP_9_BY_15, nsGui::Text::ALIGNV_TOP, nsGui::Text::ALIGNH_LEFT)
    , m_score(0)
    , m_texteScoreTitre(Vec2D(635, 0), "Score", RGBAcolor(128, 128, 128),
                        GlutFont::BITMAP_8_BY_13, nsGui::Text::ALIGNV_TOP, nsGui::Text::ALIGNH_RIGHT)
    , m_textScore(Vec2D(635, 15), std::to_string(m_score), RGBAcolor(192, 192, 192),
                  GlutFont::BITMAP_9_BY_15, nsGui::Text::ALIGNV_TOP, nsGui::Text::ALIGNH_RIGHT)
{
    nsGame::InitSpace(m_space, m_objects);
} // MainGame()

void GAME::processEvent(const nsEvent::Event_t &event)
{
    // Function called each time an event happend
    switch (event.eventType)
    {
        case nsEvent::EventType_t::Keyboard:
            switch (event.eventData.keyboardData.key)
            {
                case 'q':
                    nsGame::MoveLeft(m_objects[2]);
                    break;
                case 'd':
                    nsGame::MoveRight(m_space, m_objects[2]);
                    break;
                case ' ':
                    // On limite le tir a 1 par écran
                    if (m_objects[3].size() == 0)
                        m_objects[3].push_back(m_objects[2][rand () % m_objects[2].size ()]);
            }

            break;
        default:
            break;
    }

} // processEvent()

void GAME::update(const std::chrono::microseconds &delta)
{
    // Function called each frame, updates screen logic
    // On met tous les objets dans la matrice
    nsGame::PutAllObjects (m_objects, m_space);

    m_deplacementEnnemi += delta;
    if (m_deplacementEnnemi >= m_freqDeplacementEnnemi * m_difficulty.frequencyModifier)
    {
        m_deplacementEnnemi = std::chrono::milliseconds::zero();

        unsigned i = 0;
        while (i < m_objects[0].size())
        {
            // On cherche si un ennemi est sur une bordure
            if (m_ennemiDeplacementDroite && m_objects[0][i].second == nsGame::KSizeSpace - 1) break;
            if (!m_ennemiDeplacementDroite && m_objects[0][i].second == 0) break;

            ++i;
        }

        if (i == m_objects[0].size())
        {
            // On a trouvé personne sur un bord

            if (m_ennemiDeplacementDroite)
                // On déplace tout le monde a droite
                nsGame::MoveRight(m_space, m_objects[0]);
            else
                // On déplace tout le monde a gauche
                nsGame::MoveLeft(m_objects[0]);
        }
        else
        {
            // On a trouvé quelqu'un sur un bord
            nsGame::MoveDown(m_objects[0]);
            m_ennemiDeplacementDroite = !m_ennemiDeplacementDroite;
        }
    }

    m_tir += delta;
    if (m_objects[0].size() > 0 && m_tir >= m_freqTir * m_difficulty.frequencyModifier)
    {
        m_tir = std::chrono::milliseconds::zero();

        const unsigned selectedColumn = rand() % m_objects[0].size();
        nsGame::CPosition selectedInvader = m_objects[0][selectedColumn];

        for (unsigned i = 0; i < m_objects[0].size(); ++i)
        {
            if (m_objects[0][i].first > selectedInvader.first)
                selectedInvader = m_objects[0][i];
        }

        ++selectedInvader.first;
        m_objects[1].push_back(selectedInvader);
    }

    m_missile += delta;
    if (m_missile >= m_freqMissile * m_difficulty.frequencyModifier)
    {
        m_missile = std::chrono::milliseconds::zero();

        // On fait descendre les missiles
        nsGame::MoveDown (m_objects[1]);

        // On fait monter les torpilles
        nsGame::MoveUp (m_objects[3]);
    }

    // On gere les collisions
    unsigned Score;
    nsGame::ManageCollisions (m_objects, Score);

    m_score += Score * 10 * m_difficulty.scoreModifier;
    m_textScore.setContent(std::to_string(m_score));

    // On supprime les missiles qui sortent de l'aire de jeu
    nsGame::DeleteMissiles (m_space, m_objects[1]);

    // On supprime les torpilles qui sortent de l'aire de jeu
    nsGame::DeleteTorpedos (m_objects[3]);

    // On teste si quelqu'un a gagné
    unsigned Vict = nsGame::Victory (m_space, m_objects);
    if (Vict == 1 || Vict == 3)
    {
        // Le joueur a gagné ou l'envahisseur est tout en bas
        saveAndExit(Vict == 1);
    }
    else if (Vict == 2)
    {
        // L'envahisseur a gagné
        if (m_vies > 0)
        {
            --m_vies;
            m_texteVies.setContent(std::to_string(m_vies));

            nsGame::AddPlayer(m_space, m_objects);
        }
        else
        {
            saveAndExit(false);
        }
    }

} // update()

void GAME::draw(MinGL &window)
{
    // Function called each frame, draws screen elements

    // Inject to the window everything that must be drawn
    for (unsigned i = 0; i < m_space.size(); ++i)
    {
        for (unsigned j = 0; j < m_space[i].size(); ++j)
        {
            const Vec2D actualPos(8 + 48*j, 56 + 48*i);
            const Vec2D endPos = actualPos + Vec2D(48, 48);
            switch (m_space[i][j])
            {
                case nsGame::KInsideInvader:
                    // Char for the invader
                    window << Rectangle(actualPos, endPos, KRed);
                    break;
                case nsGame::KInsideMe:
                    // Char for the player
                    window << Rectangle(actualPos, endPos, KBlue);

                    break;
                case nsGame::KTorpedo:
                    // Char for the torpedo (player weapon)
                    window << Rectangle(actualPos, endPos, KYellow);

                    break;
                case nsGame::KMissile:
                    // Char for the missile (invader weapon)
                    window << Rectangle(actualPos, endPos, KPurple);

                    break;
            }
        }
    }

    // On affiche les textes de la HUD
    window << m_texteViesTitre << m_texteVies;
    window << m_texteScoreTitre << m_textScore;

} // draw()

std::unique_ptr<IDrawable> GAME::clone() const
{
    return std::unique_ptr<MainGame>(new MainGame(*this));
} // clone()

void GAME::saveAndExit(const bool &playerWon)
{
    // On enregistre quelques données de la partie en cours
    std::ofstream savefile("save.csv");
    savefile << (playerWon ? 1 : 0) << "," << m_score;
    savefile.close();

    // On revient au menu principal
    requestScreenChange(nsScreen::ScreenIdentifiers::ID_TitleMenu);
} // saveAndExit()

#undef GAME
