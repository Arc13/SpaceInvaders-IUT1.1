/**
 * @file end_game.cpp
 * @brief The screen shown at the end of the game
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 18 janvier 2020
 */

#include "end_game.h"

#include <fstream>
#include <iomanip>

#include "../score/score_mgr.h"
#include "../tools/myexception.h"

#define ENDGAME nsScreen::EndGame

ENDGAME::EndGame()
    : m_enteringName(true)
    , m_name()
    , m_nameTitle(Vec2D(320, 200), "Entrez votre nom:", RGBAcolor(128, 128, 128), GlutFont::BITMAP_8_BY_13, nsGui::Text::ALIGNH_CENTER)
    , m_nameText(Vec2D(320, 220), "", RGBAcolor(192, 192, 192), GlutFont::BITMAP_9_BY_15, nsGui::Text::ALIGNH_CENTER)
    , m_mainMenuButton("Menu principal", Vec2D(10, 580), Vec2D(150, 50), RGBAcolor(51, 51, 51, 164))
    , m_topScoreButton("Top scores", Vec2D(480, 580), Vec2D(150, 50), RGBAcolor(51, 51, 51, 164))
    , m_scoreSaved(false)
    , m_scoreSavedText(Vec2D(320, 320), "", KRed, GlutFont::BITMAP_9_BY_15, nsGui::Text::ALIGNH_CENTER)
    , m_hasWon(false)
    , m_score(0)
{
    // On ouvre la dernière session et vérifie si le fichier est bien ouvert
    std::ifstream lastSessionFile("last_session.csv");
    if (!lastSessionFile.is_open())
        throw MyException(nsUtil::kFileNotFound);

    lastSessionFile >> m_hasWon;
    lastSessionFile.ignore();
    lastSessionFile >> m_score;
} // EndGame()

void ENDGAME::processEvent(const nsEvent::Event_t &event)
{
    switch (event.eventType)
    {
        case nsEvent::EventType_t::Keyboard:
        {
            // On ne lit plus les entrées des que l'utilisateur a fini de taper son nom
            if (!m_enteringName) return;

            const char key = event.eventData.keyboardData.key;
            switch (key)
            {
                case 0x08:
                    // Retour a la ligne
                    if (m_name.size() > 0)
                        m_name.pop_back();

                    break;
                case 0x0A:
                case 0x0D:
                    // Touche entrée
                    if (m_name.size() > 0)
                    {
                        // Un nom a été entré, on peut passer a sa sauvegarde
                        m_enteringName = false;

                        m_scoreSaved = nsScore::EnregistrerScoreFinPartie(m_name, m_score);
                        stringstream Str;
                        if (m_scoreSaved)
                            Str << "Bravo " << m_name << " ton score est " << m_score << endl;
                        else
                            Str << "Bravo " << m_name << " ton score est " << m_score << endl
                                        << "Mais il ne fait partie des 10 meilleurs il n'est donc pas enregistrer";

                        m_scoreSavedText.setContent(Str.str());
                    }

                    break;
                default:
                    // N'importe quelle autre caractère imprimable, on met dans la string
                    if (isprint(key))
                        m_name += key;

                    break;
            }

            m_nameText.setContent(m_name);

            break;
        }
        case nsEvent::EventType_t::MouseClick:
        {
            // On autorise pas le clic tant que l'utilisateur écrit son nom
            if (m_enteringName) return;

            const Vec2D mousePos(event.eventData.clickData.x, event.eventData.clickData.y);
            if (mousePos >= m_mainMenuButton.getPosition() && mousePos <= m_mainMenuButton.getPosition() + m_mainMenuButton.getSize())
            {
                // L'utilisateur a cliqué sur le bouton du menu titre
                requestScreenChange(nsScreen::ScreenIdentifiers::ID_TitleMenu);
            }
            else if (mousePos >= m_topScoreButton.getPosition() && mousePos <= m_topScoreButton.getPosition() + m_topScoreButton.getSize())
            {
                // L'utilisateur a cliqué sur le bouton des top scores
                requestScreenChange(nsScreen::ScreenIdentifiers::ID_TopScores);
            }
        }
        default:
            break;
    }
} // processEvent()

void ENDGAME::update(const std::chrono::microseconds &delta)
{

} // update()

void ENDGAME::draw(MinGL &window)
{
    window << m_nameTitle << m_nameText;

    if (!m_enteringName)
    {
        window << m_scoreSavedText;

        window << m_mainMenuButton;
        window << m_topScoreButton;
    }
} // draw()

std::unique_ptr<IDrawable> ENDGAME::clone() const
{
    return std::unique_ptr<EndGame>(new EndGame(*this));
} // clone()

#undef ENDGAME
