#include "main_game.h"

#include <iostream>

#include "gridmanager/manage.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"
#include "gridmanager/manage_const.h"

#define GAME nsScreen::MainGame

GAME::MainGame()
    : m_ennemi(Vec2D(50, 50), Vec2D(100, 100), KRed)
    , m_frtir (1000)
    , m_frennemi (3000)
    , m_frmissile (100)
    , m_Vict (2)
{
    nsGame::InitSpace(m_space, m_objects);
} // GAME()

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
    if (m_deplacementEnnemi >= m_frennemi)
    {
        nsGame::MoveDown (m_objects[0]);
        m_deplacementEnnemi = std::chrono::milliseconds::zero();
    }

    for (unsigned i = m_space.size(); --i > 0;)
    {
        for (unsigned j = m_space[i].size(); --j > 0;)
        {
            if (m_space[i][j] == nsGame::KInsideInvader)
                break;
        }
    }
    m_tir += delta;
    if (m_tir >= m_frtir)
    {
        m_objects[1].push_back(m_objects[0][rand () % m_objects[0].size ()]);
        m_tir = std::chrono::milliseconds::zero();
    }

    m_missile += delta;
    if (m_missile >= m_frmissile)
    {
        nsGame::MoveDown (m_objects[1]);
        m_missile = std::chrono::milliseconds::zero();
    }
    // On fait monter les torpilles
    nsGame::MoveUp (m_objects[3]);
    // On gere les collisions
    nsGame::ManageCollisions (m_objects);
    // On supprime les missiles qui sortent de l'aire de jeu
    nsGame::DeleteMissiles (m_space, m_objects[1]);
    // On supprime les torpilles qui sortent de l'aire de jeu
    nsGame::DeleteTorpedos (m_objects[3]);
    // On teste si quelqu'un a gagné
    m_Vict = nsGame::Victory (m_space, m_objects);

    if (m_Vict == 2 && m_frennemi > std::chrono::milliseconds(500) && m_frtir > std::chrono::milliseconds(100) && m_frmissile > std::chrono::milliseconds(10) )
    {
        m_frennemi -= std::chrono::milliseconds(1000);
        m_frtir -= std::chrono::milliseconds(100);
        m_frmissile -= std::chrono::milliseconds(10);
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
            switch (m_space[i][j])
            {
                case nsGame::KInsideInvader:
                    // Char for the invader
                    window << Rectangle(Vec2D(32 + 32*j, 32 + 32*i), Vec2D(64 + 32*j, 64 + 32*i), KRed);
                    break;
                case nsGame::KInsideMe:
                    // Char for the player
                window << Rectangle(Vec2D(32 + 32*j, 32 + 32*i), Vec2D(64 + 32*j, 64 + 32*i), KBlue);

                    break;
                case nsGame::KTorpedo:
                    // Char for the torpedo (player weapon)
                    window << Rectangle(Vec2D(32 + 32*j, 32 + 32*i), Vec2D(64 + 32*j, 64 + 32*i), KYellow);

                    break;
                case nsGame::KMissile:
                    // Char for the missile (invader weapon)
                    window << Rectangle(Vec2D(32 + 32*j, 32 + 32*i), Vec2D(64 + 32*j, 64 + 32*i), KPurple);

                    break;
            }
        }
    }

} // draw()

std::unique_ptr<IDrawable> GAME::clone() const
{
    return std::unique_ptr<MainGame>(new MainGame(*this));
} // clone()

#undef GAME
