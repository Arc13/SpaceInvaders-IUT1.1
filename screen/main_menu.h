/**
 * @file main_menu.h
 * @brief The main menu screen definition
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef SCREENMAINMENU_H
#define SCREENMAINMENU_H

#include "iscreen.h"

#include <iostream>

#include "../transition/transition_engine.h"

#include "gui/fat_button.h"

namespace nsScreen {

/**
 * @class MainMenu
 * @brief Set of elements representing the main menu of the game
 */
class MainMenu : public IScreen
{
public:
    /**
     * @brief Constructor for the MainMenu class
     * @fn MainMenu();
     */
    MainMenu();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;

private:
    nsTransition::TransitionEngine m_transitionEngine;

    nsGui::FatButton m_fatBtn;
    nsGui::FatButton m_fatBtn2;
    nsGui::FatButton m_fatBtn3;

    bool m_stoptrans;
};

} // namespace nsScreen

#endif // SCREENMAINMENU_H
