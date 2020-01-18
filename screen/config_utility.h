#ifndef CONFIG_UTILITY_H
#define CONFIG_UTILITY_H

#include "iscreen.h"

#include "../config/config.h"
#include "../figs/rectangle.h"
#include "../game/difficulty.hpp"
#include "../transition/transition_engine.h"

#include "../gui/button.h"
#include "../gui/text.h"

namespace nsScreen {

class ConfigUtility : public IScreen
{
public:
    ConfigUtility();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    nsConfig::TableauCommande m_configuration;

    nsGui::Text m_screenTitle;

    /**
     * @brief m_mainMenuButton : Bouton de retour vers le menu principal
     */
    nsGui::Button m_mainMenuButton;

    unsigned getDifficulty();
    void setDifficulty(const unsigned &difficulty);
    void updateDifficultyText();

    nsGui::Text m_difficultyTitle;
    nsGui::Text m_difficultyText;
    Rectangle m_difficultyTextBackground;
    nsGui::Button m_difficultyDecreaseButton;
    nsGui::Button m_difficultyIncreaseButton;

    enum Control {
        CONTROL_NONE,

        CONTROL_RIGHT,
        CONTROL_LEFT,
        CONTROL_SHOOT,
    };

    std::string getKeyAsText(const char &key);
    void updateControlText(const Control &control);
    void deselectControl();
    void selectControl(const Control &control);
    void assignControlToKey(const Control &control, const char &key);

    Control m_selectedControl;
    nsGui::Text m_controlsTitle;
    nsGui::Text m_controlsRight;
    nsGui::Text m_controlsLeft;
    nsGui::Text m_controlsShoot;

    nsTransition::TransitionEngine m_transitionEngine;
};

}

#endif // CONFIG_UTILITY_H
