/**
 * @file main_menu.h
 * @brief The main menu screen definition
 * @author SOLLIER Alexandre
 * @version 1.1
 * @date 09 janvier 2020
 */

#ifndef SCREENMAINMENU_H
#define SCREENMAINMENU_H

#include "iscreen.h"

#include "../gui/button.h"
#include "../gui/text.h"

#include "../transition/transition_engine.h"
#include "../transition/transition_types.h"

namespace nsScreen {

/**
 * @class TitleMenu
 * @brief Set of elements representing the title screen of the game
 */
class TitleMenu : public IScreen
{
public:
    /**
     * @brief Constructor for the TitleMenu class
     * @fn TitleMenu();
     */
    TitleMenu();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_transitionEngine : An instance of the transition engine
     */
    nsTransition::TransitionEngine m_transitionEngine;

    /**
     * @brief m_playButtonHovered : Set if the mouse cursor is on the play button
     */
    bool m_playButtonHovered;

    /**
     * @brief m_playButton : The button to start the game
     */
    nsGui::Button m_playButton;

    /**
     * @brief Executes the title screen apparition animation
     * @fn void executeTitleAppearanceAnimation();
     */
    void executeTitleAppearanceAnimation();

    /**
     * @brief Executes the title screen halo effect
     * @fn void executeTitleHaloEffect();
     */
    void executeTitleHaloEffect();

    /**
     * @brief m_titleShown : Flag indicating if the title is currently shown
     */
    bool m_titleShown;

    /**
     * @brief m_titleEnableAnimation : Flag indicating if the title can have the halo effect
     */
    bool m_titleEnableAnimation;

    /**
     * @brief m_titleLastHaloTime : Time since the last halo effect occured
     */
    nsTransition::SystemDuration_t m_titleLastHaloTime;

    /**
     * @brief m_titleText : Vector containing all the lines of the title
     */
    std::vector<nsGui::Text> m_titleText;
};

} // namespace nsScreen

#endif // SCREENMAINMENU_H
