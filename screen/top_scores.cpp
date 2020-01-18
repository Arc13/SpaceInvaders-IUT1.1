/**
 * @file top_scores.cpp
 * @brief The screen showing the 10 top scores
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 18 janvier 2020
 */

#include "top_scores.h"

#include "../score/score_mgr.h"

#define TOPSCORES nsScreen::TopScores

TOPSCORES::TopScores()
    : m_mainMenuButton("Menu principal", Vec2D(10, 580), Vec2D(150, 50), RGBAcolor(51, 51, 51, 164))
{

}

void TOPSCORES::processEvent(const nsEvent::Event_t &event)
{
    switch (event.eventType)
    {
        case nsEvent::EventType_t::MouseClick:
        {
            const Vec2D mousePos(event.eventData.clickData.x, event.eventData.clickData.y);
            if (mousePos >= m_mainMenuButton.getPosition() && mousePos <= m_mainMenuButton.getPosition() + m_mainMenuButton.getSize())
            {
                // L'utilisateur a cliqué sur le bouton du menu titre
                requestScreenChange(nsScreen::ScreenIdentifiers::ID_TitleMenu);
            }
        }
        default:
            break;
    }
}

void TOPSCORES::update(const std::chrono::microseconds &delta)
{

}

void TOPSCORES::draw(MinGL &window)
{
    nsScore::ChargerEtAfficherTopScores(window);

    window << m_mainMenuButton;
}

std::unique_ptr<IDrawable> TOPSCORES::clone() const
{
    return std::unique_ptr<TopScores>(new TopScores(*this));
}
