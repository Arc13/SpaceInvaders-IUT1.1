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

namespace nsScreen {

/**
 * @class MainMenu
 * @brief Set of elements representing the main menu of the game
 */
class MainMenu : public IScreen
{
public:
    /**
     * @brief Called whenever an user input happens
     * @param[in] event : The event that just happened
     * @fn virtual void processEvent(const nsEvent::Event &event) override;
     */
    virtual void processEvent(const nsEvent::Event_t &event) override;

    /**
     * @brief Called every frame to update screen's logic
     * @param[in] delta : Time that the previous frame took to render
     * @fn virtual void update(const float &delta) override;
     */
    virtual void update(const float &delta) override;

    /**
     * @brief Called every frame to draw the screen
     * @param[in] window : The window to draw to
     * @fn virtual void draw(MinGL &window) override;
     */
    virtual void draw(MinGL &window) override;
};

} // namespace nsScreen

#endif // SCREENMAINMENU_H
