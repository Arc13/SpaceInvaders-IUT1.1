#include "config_utility.h"

#include <sstream>

#define CONFIGUTILITY nsScreen::ConfigUtility

CONFIGUTILITY::ConfigUtility()
    : m_screenTitle(Vec2D(320, 130), "Options", RGBAcolor(128, 128, 128),
                    GlutFont::BITMAP_HELVETICA_18, nsGui::Text::ALIGNH_CENTER)
    , m_mainMenuButton("Menu principal", Vec2D(10, 580), Vec2D(150, 50), RGBAcolor(51, 51, 51, 164))
    , m_difficultyTitle(Vec2D(15, 230), "Niveau", KWhite, GlutFont::BITMAP_HELVETICA_18)
    , m_difficultyText(Vec2D(102, 257), "", KWhite, GlutFont::BITMAP_HELVETICA_12, nsGui::Text::ALIGNH_CENTER, nsGui::Text::ALIGNV_CENTER)
    , m_difficultyTextBackground(Vec2D(45, 245), Vec2D(160, 275), RGBAcolor(51, 51, 51, 164), KTransparent)
    , m_difficultyDecreaseButton("<", Vec2D(15, 245), Vec2D(30, 30), RGBAcolor(51, 51, 51, 164))
    , m_difficultyIncreaseButton(">", Vec2D(160, 245), Vec2D(30, 30), RGBAcolor(51, 51, 51, 164))
    , m_selectedControl(Control::CONTROL_NONE)
    , m_controlsTitle(Vec2D(15, 330), "Controles", KWhite, GlutFont::BITMAP_HELVETICA_18)
    , m_controlsRight(Vec2D(40, 365), "", RGBAcolor(192, 192, 192, 192), GlutFont::BITMAP_HELVETICA_18)
    , m_controlsLeft(Vec2D(40, 390), "", RGBAcolor(192, 192, 192, 192), GlutFont::BITMAP_HELVETICA_18)
    , m_controlsShoot(Vec2D(40, 415), "", RGBAcolor(192, 192, 192, 192), GlutFont::BITMAP_HELVETICA_18)
{
    nsConfig::ReadCommande(m_configuration);

    updateControlText(CONTROL_RIGHT);
    updateControlText(CONTROL_LEFT);
    updateControlText(CONTROL_SHOOT);

    updateDifficultyText();


} // ConfigUtility()

void CONFIGUTILITY::processEvent(const nsEvent::Event_t &event)
{
    switch (event.eventType)
    {
        case nsEvent::EventType_t::MouseClick:
        {
            // On ne veut gérer qu'au relachement de la souris
            if (event.eventData.clickData.state == 0) return;

            const Vec2D mousePos(event.eventData.clickData.x, event.eventData.clickData.y);

            if (mousePos.isInside(m_mainMenuButton.getPosition(), m_mainMenuButton.getPosition() + m_mainMenuButton.getSize()))
            {
                // L'utilisateur a cliqué sur le bouton du menu titre, on enregistre les préférences
                nsConfig::WriteCommande(m_configuration);
                requestScreenChange(nsScreen::ScreenIdentifiers::ID_TitleMenu);
            }
            else if (mousePos.isInside(m_difficultyDecreaseButton.getPosition(), m_difficultyDecreaseButton.getPosition() + m_difficultyDecreaseButton.getSize()))
            {
                // L'utilisateur a cliqué sur le bouton pour baisser la difficulté
                const unsigned difficulty = getDifficulty();
                if (difficulty > 0)
                    setDifficulty(difficulty - 1);
                else
                    setDifficulty(nsGame::KDifficultyName.size() - 1);
            }
            else if (mousePos.isInside(m_difficultyIncreaseButton.getPosition(), m_difficultyIncreaseButton.getPosition() + m_difficultyIncreaseButton.getSize()))
            {
                // L'utilisateur a cliqué sur le bouton pour augmenter la difficulté
                const unsigned difficulty = getDifficulty();
                if (difficulty < nsGame::KDifficultyName.size() - 1)
                    setDifficulty(difficulty + 1);
                else
                    setDifficulty(0);
            }

            if (m_selectedControl == CONTROL_NONE)
            {
                if (mousePos.isInside(m_controlsRight.computeVisiblePosition(), m_controlsRight.computeVisibleEndPosition()))
                {
                    // L'utilisateur a cliqué sur le contrôle Droite
                    selectControl(CONTROL_RIGHT);
                }
                else if (mousePos.isInside(m_controlsLeft.computeVisiblePosition(), m_controlsLeft.computeVisibleEndPosition()))
                {
                    // L'utilisateur a cliqué sur le contrôle Gauche
                    selectControl(CONTROL_LEFT);
                }
                else if (mousePos.isInside(m_controlsShoot.computeVisiblePosition(), m_controlsShoot.computeVisibleEndPosition()))
                {
                    // L'utilisateur a cliqué sur le contrôle Tir
                    selectControl(CONTROL_SHOOT);
                }
            }
            else
            {
                // Aucun contrôle séléctionné, on déselectionne l'actuel
                deselectControl();
            }
        }
        case nsEvent::EventType_t::Keyboard:
        {
            const char key = event.eventData.keyboardData.key;

            // On assigne le contrôle sélectionné a la touche
            if (m_selectedControl != CONTROL_NONE && isprint(key))
            {
                assignControlToKey(m_selectedControl, key);
                deselectControl();
            }
        }
        default:
            break;
    }
} // processEvent()

void CONFIGUTILITY::update(const std::chrono::microseconds &delta)
{
    m_transitionEngine.update(delta);
} // update()

void CONFIGUTILITY::draw(MinGL &window)
{
    window << m_screenTitle;
    window << m_mainMenuButton;

    window << m_difficultyTitle
           << m_difficultyDecreaseButton
           << m_difficultyTextBackground
           << m_difficultyText
           << m_difficultyIncreaseButton;

    window << m_controlsTitle
           << m_controlsRight
           << m_controlsLeft
           << m_controlsShoot;
} // draw()

std::unique_ptr<IDrawable> CONFIGUTILITY::clone() const
{
    return std::unique_ptr<ConfigUtility>(new ConfigUtility(*this));
} // clone()

unsigned CONFIGUTILITY::getDifficulty()
{
    std::istringstream converter(std::string(1, m_configuration[3]));
    unsigned result;
    converter >> result;

    return result;
} // getDifficulty()

void CONFIGUTILITY::setDifficulty(const unsigned &difficulty)
{
    std::istringstream converter(std::to_string(difficulty));
    char result;
    converter >> result;

    m_configuration[3] = result;

    updateDifficultyText();
} // setDifficulty()

void nsScreen::ConfigUtility::updateDifficultyText()
{
    m_difficultyText.setContent(nsGame::KDifficultyName[getDifficulty()]);
} // updateDifficultyText()

std::string CONFIGUTILITY::getKeyAsText(const char &key)
{
    switch (key)
    {
        case ' ':
            return "Espace";
    }

    return std::string(1, key);
} // getKeyAsText()

void CONFIGUTILITY::updateControlText(const nsScreen::ConfigUtility::Control &control)
{
    switch (control)
    {
        case CONTROL_RIGHT:
            m_controlsRight.setContent("Droite - " + getKeyAsText(m_configuration[0]));
            break;
        case CONTROL_LEFT:
            m_controlsLeft.setContent("Gauche - " + getKeyAsText(m_configuration[1]));
            break;
        case CONTROL_SHOOT:
            m_controlsShoot.setContent("Tir - " + getKeyAsText(m_configuration[2]));
            break;
        default:
            break;
    }
} // updateControlText()

void CONFIGUTILITY::deselectControl()
{
    switch (m_selectedControl)
    {
        case CONTROL_RIGHT:
            m_transitionEngine.finishEveryTransitionOfTarget(m_controlsRight, nsTransition::Transition::TransitionFinishModes::FINISH_START);
            break;
        case CONTROL_LEFT:
            m_transitionEngine.finishEveryTransitionOfTarget(m_controlsLeft, nsTransition::Transition::TransitionFinishModes::FINISH_START);
            break;
        case CONTROL_SHOOT:
            m_transitionEngine.finishEveryTransitionOfTarget(m_controlsShoot, nsTransition::Transition::TransitionFinishModes::FINISH_START);
            break;
        default:
            break;
    }

    updateControlText(m_selectedControl);
    m_selectedControl = CONTROL_NONE;
} // deselectControl()

void CONFIGUTILITY::selectControl(const nsScreen::ConfigUtility::Control &control)
{
    m_selectedControl = control;

    switch (control)
    {
        case CONTROL_RIGHT:
            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsRight, nsGui::Text::TRANSITION_COLOR_RGB,
                                                                              std::chrono::milliseconds(250), {255, 255, 255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));

            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsRight, nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                                              std::chrono::milliseconds(250), {255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));
            break;
        case CONTROL_LEFT:
            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsLeft, nsGui::Text::TRANSITION_COLOR_RGB,
                                                                              std::chrono::milliseconds(250), {255, 255, 255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));

            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsLeft, nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                                              std::chrono::milliseconds(250), {255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));
            break;
        case CONTROL_SHOOT:
            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsShoot, nsGui::Text::TRANSITION_COLOR_RGB,
                                                                              std::chrono::milliseconds(250), {255, 255, 255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));

            m_transitionEngine.startContract(nsTransition::TransitionContract(m_controlsShoot, nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                                              std::chrono::milliseconds(250), {255}, std::chrono::seconds::zero(),
                                                                              nsTransition::TransitionContract::MODE_LOOP_SMOOTH));
            break;
        default:
            break;
    }
} // selectControl()

void CONFIGUTILITY::assignControlToKey(const nsScreen::ConfigUtility::Control &control, const char &key)
{
    switch (control)
    {
        case CONTROL_RIGHT:
            m_configuration[0] = key;
            break;
        case CONTROL_LEFT:
            m_configuration[1] = key;
            break;
        case CONTROL_SHOOT:
            m_configuration[2] = key;
            break;
        default:
            break;
    }
} // assignControlToKey()

#undef CONFIGUTILITY
