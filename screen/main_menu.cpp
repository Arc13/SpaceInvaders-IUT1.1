#include "main_menu.h"

#include <iostream>

#include "gui/text.h"
#include "gui/star_background.h"

#include "figs/line.h"
#include "figs/rectangle.h"
#include "figs/triangle.h"
#include "figs/circle.h"
#include "figs/figure.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"

#define MAINMENU nsScreen::MainMenu

MAINMENU::MainMenu()
    : m_fatBtn(Vec2D(50, 50), Vec2D(50, 50))
    , m_fatBtn2(Vec2D(150, 50), Vec2D(50, 50))
    , m_fatBtn3(Vec2D(250, 50), Vec2D(50, 50))
{} // MainMenu()

void MAINMENU::processEvent(const nsEvent::Event_t &event)
{
    // Function called each time an event happend
    if (event.eventType == nsEvent::MouseClick) {
        std::cout << "click: " << event.eventData.clickData.x << ", " << event.eventData.clickData.y << std::endl;
    } else if (event.eventType == nsEvent::MouseMove) {
        //std::cout << "move: " << event.eventData.moveData.x << ", " << event.eventData.moveData.y << std::endl;
    } else if (event.eventType == nsEvent::Keyboard) {
        std::cout << "keyboard: " << event.eventData.keyboardData.x << ", " << event.eventData.keyboardData.y << std::endl;

        nsTransition::TransitionContract ctr = nsTransition::TransitionContract(m_fatBtn, nsGui::FatButton::TRANSITION_FIRST_RGB, std::chrono::seconds(2), {255, 255, 255});
        ctr.setDestinationCallback([]() {
            std::cout << "First transition has finished!" << std::endl;
        });
        m_transitionEngine.startContract(ctr);
        m_transitionEngine.startContract(nsTransition::TransitionContract(m_fatBtn, nsGui::FatButton::TRANSITION_POSITION, std::chrono::seconds(2), {50, 200}));

        m_transitionEngine.startContract(nsTransition::TransitionContract(m_fatBtn2, nsGui::FatButton::TRANSITION_FIRST_RGB, std::chrono::seconds(2), {255, 255, 255}, nsTransition::TransitionContract::MODE_LOOP));
        m_transitionEngine.startContract(nsTransition::TransitionContract(m_fatBtn2, nsGui::FatButton::TRANSITION_POSITION, std::chrono::seconds(2), {150, 200}, nsTransition::TransitionContract::MODE_LOOP));

        m_transitionEngine.startContract(nsTransition::TransitionContract(m_fatBtn3, nsGui::FatButton::TRANSITION_FIRST_RGB, std::chrono::seconds(2), {255, 255, 255}, nsTransition::TransitionContract::MODE_LOOP_SMOOTH));
        m_transitionEngine.startContract(nsTransition::TransitionContract(m_fatBtn3, nsGui::FatButton::TRANSITION_POSITION, std::chrono::seconds(2), {250, 200}, nsTransition::TransitionContract::MODE_LOOP_SMOOTH));
    }
} // processEvent()

void MAINMENU::update(const std::chrono::microseconds &delta)
{
    // Function called each frame, updates screen logic
    m_transitionEngine.update(delta);
} // update()

void MAINMENU::draw(MinGL &window)
{
    // Function called each frame, draws screen elements

    // Inject to the window everything that must be drawn
    window << nsGui::Text(Vec2D(10, 110), "BITMAP 8x13", KRed);
    window << nsGui::Text(Vec2D(10, 125), "BITMAP 9x15", KRed, GlutFont::BITMAP_9_BY_15);
    window << nsGui::Text(Vec2D(10, 140), "HELVETICA 10", KBlue, GlutFont::BITMAP_HELVETICA_10);
    window << nsGui::Text(Vec2D(10, 155), "HELVETICA 12", KBlue, GlutFont::BITMAP_HELVETICA_12);
    window << nsGui::Text(Vec2D(10, 175), "HELVETICA 18", KBlue, GlutFont::BITMAP_HELVETICA_18);
    window << nsGui::Text(Vec2D(10, 195), "TIMES NEW ROMAN 10", KGreen, GlutFont::BITMAP_TIMES_ROMAN_10);
    window << nsGui::Text(Vec2D(10, 215), "TIMES NEW ROMAN 24", KGreen, GlutFont::BITMAP_TIMES_ROMAN_24);

    window << Rectangle(Vec2D(280, 280), Vec2D(300, 300), KBlue, KPurple);
    window << Circle(Vec2D(150, 150), 40, KYellow, KRed);
    window << Line(Vec2D(400, 400), Vec2D(500, 400), KRed);
    window << Triangle(Vec2D(100, 100), Vec2D(150, 100), Vec2D(100, 150), KCyan, KRed);

    window << m_fatBtn;
    window << m_fatBtn2;
    window << m_fatBtn3;
} // draw()

#undef MAINMENU
