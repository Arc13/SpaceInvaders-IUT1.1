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
    MainMenu();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;

private:
    TransitionEngine m_transitionEngine;

    FatButton m_fatBtn;
};

} // namespace nsScreen

#endif // SCREENMAINMENU_H
