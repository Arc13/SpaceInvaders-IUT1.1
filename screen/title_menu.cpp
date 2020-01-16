/**
 * @file main_menu.cpp
 * @brief The main menu screen definition
 * @author SOLLIER Alexandre
 * @version 1.1
 * @date 09 janvier 2020
 */

#include "title_menu.h"

#include <iostream>

#define TITLEMENU nsScreen::TitleMenu

TITLEMENU::TitleMenu()
    : m_playButtonHovered(false)
    , m_playButton("Jouer", Vec2D(220, 320), Vec2D(200, 60), RGBAcolor(86, 204, 242, 192), RGBAcolor(47, 128, 237, 192))
    , m_titleShown(false)
    , m_titleEnableAnimation(false)
    , m_titleLastHaloTime(std::chrono::seconds::zero())
{
    // Push every line to the vector containing Text drawables
    const std::vector<std::string> titleLines{" .d8888b.",
                                              "d88P  Y88b",
                                              "Y88b.",
                                              " \"Y888b.  88888b.  8888b.  .d8888b .d88b.",
                                              "    \"Y88b.888 \"88b    \"88bd88P\"   d8P  Y8b",
                                              "      \"888888  888.d888888888     88888888",
                                              "Y88b  d88P888 d88P888  888Y88b.   Y8b.",
                                              " \"Y8888P\" 88888P\" \"Y888888 \"Y8888P \"Y8888",
                                              "          888",
                                              "          888",
                                              "          888",
                                              "",
                                              " .d88888b.         888                        888",
                                              "d88P\" \"Y88b        888                        888",
                                              "888     888        888                        888",
                                              "888     888888  888888888888  888 8888b.  .d88888 .d88b. 888d888.d8888b",
                                              "888     888888  888888   888  888    \"88bd88\" 888d8P  Y8b888P\"  88K",
                                              "888     888888  888888   Y88  88P.d888888888  88888888888888    \"Y8888b.",
                                              "Y88b. .d88PY88b 888Y88b.  Y8bd8P 888  888Y88b 888Y8b.    888         X88 ",
                                              " \"Y88888P\"  \"Y88888 \"Y888  Y88P  \"Y888888 \"Y88888 \"Y8888 888     88888P'"};

    for (unsigned i = 0; i < titleLines.size(); ++i)
    {
        m_titleText.push_back(nsGui::Text(Vec2D(10 + 2*i, 20 + 13*i), titleLines[i], RGBAcolor(160, 160, 160, 0)));
    }
} // MainMenu()

void TITLEMENU::processEvent(const nsEvent::Event_t &event)
{
    // Function called each time an event happend
    switch (event.eventType)
    {
        case nsEvent::EventType_t::MouseMove:
        {
            const Vec2D mousePos(event.eventData.moveData.x, event.eventData.moveData.y);
            if (!m_playButtonHovered && mousePos >= m_playButton.getPosition() && mousePos <= m_playButton.getPosition() + m_playButton.getSize())
            {
                // Mouse moved where the play button is located, set button transparency to 255
                m_playButtonHovered = true;
                m_transitionEngine.finishEveryTransitionOfTarget(m_playButton);

                m_transitionEngine.startContract(nsTransition::TransitionContract(m_playButton,
                                                                                  nsGui::Button::TRANSITION_FIRST_ALPHA,
                                                                                  std::chrono::milliseconds(500), {255}));
                m_transitionEngine.startContract(nsTransition::TransitionContract(m_playButton,
                                                                                  nsGui::Button::TRANSITION_SECOND_ALPHA,
                                                                                  std::chrono::milliseconds(500), {255}));
            }
            else if (m_playButtonHovered && !(mousePos >= m_playButton.getPosition() && mousePos <= m_playButton.getPosition() + m_playButton.getSize()))
            {
                // Mouse moved outside of the play button location
                m_playButtonHovered = false;
                m_transitionEngine.finishEveryTransitionOfTarget(m_playButton);

                m_transitionEngine.startContract(nsTransition::TransitionContract(m_playButton,
                                                                                  nsGui::Button::TRANSITION_FIRST_ALPHA,
                                                                                  std::chrono::milliseconds(500), {192}));
                m_transitionEngine.startContract(nsTransition::TransitionContract(m_playButton,
                                                                                  nsGui::Button::TRANSITION_SECOND_ALPHA,
                                                                                  std::chrono::milliseconds(500), {192}));
            }

            break;
        }
        case nsEvent::EventType_t::MouseClick:
        {
            const Vec2D mousePos(event.eventData.clickData.x, event.eventData.clickData.y);
            if (mousePos >= m_playButton.getPosition() && mousePos <= m_playButton.getPosition() + m_playButton.getSize())
            {
                // The user clicked on the play button
                requestScreenChange(nsScreen::ScreenIdentifiers::ID_MainGame);
            }

            break;
        }
        default:
            break;
    }
} // processEvent()

void TITLEMENU::update(const std::chrono::microseconds &delta)
{
    // Function called each frame, updates screen logic
    m_transitionEngine.update(delta);

    // This is the first update, we must show the game title
    if (!m_titleShown)
    {
        m_titleShown = true;
        executeTitleAppearanceAnimation();
    }

    // Manage the title halo effect
    m_titleLastHaloTime += delta;
    if (m_titleEnableAnimation && m_titleLastHaloTime >= std::chrono::seconds(4))
    {
        // The animation is enabled and enough time has passed
        m_titleLastHaloTime = std::chrono::seconds::zero();
        executeTitleHaloEffect();
    }
} // update()

void TITLEMENU::draw(MinGL &window)
{
    // Function called each frame, draws screen elements
    window << m_playButton;

    // Draw every line of the title
    for (const nsGui::Text &line : m_titleText)
    {
        window << line;
    }
} // draw()

std::unique_ptr<IDrawable> TITLEMENU::clone() const
{
    return std::unique_ptr<TitleMenu>(new TitleMenu(*this));
} // clone()

void TITLEMENU::executeTitleAppearanceAnimation()
{
    // Set every line of the title to an alpha of 192
    for (unsigned i = 0; i < m_titleText.size() - 1; ++i)
    {
        m_transitionEngine.startContract(nsTransition::TransitionContract(m_titleText[i],
                                                                          nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                                          std::chrono::milliseconds(1000), {192},
                                                                          std::chrono::milliseconds(50) * i));
    }

    // When the last animation is done, we can enable the "halo" animation
    const unsigned lastTextIndex = m_titleText.size() - 1;
    nsTransition::TransitionContract lastContract(m_titleText[lastTextIndex],
                                                  nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                  std::chrono::milliseconds(1000), {192},
                                                  std::chrono::milliseconds(50) * lastTextIndex);
    lastContract.setDestinationCallback([&]() {
        m_titleEnableAnimation = true;
        m_titleLastHaloTime = std::chrono::seconds::zero();
    });
    m_transitionEngine.startContract(lastContract);
} // executeTitleAppearanceAnimation()

void TITLEMENU::executeTitleHaloEffect()
{
    // Set every line of the title to a white color, temporarily
    for (unsigned i = 0; i < m_titleText.size(); ++i)
    {
        m_transitionEngine.startContract(nsTransition::TransitionContract(m_titleText[i],
                                                                          nsGui::Text::TRANSITION_COLOR_RGB,
                                                                          std::chrono::milliseconds(150), {255, 255, 255},
                                                                          std::chrono::milliseconds(50) * i,
                                                                          nsTransition::TransitionContract::MODE_FINITE_REVERSE));

        m_transitionEngine.startContract(nsTransition::TransitionContract(m_titleText[i],
                                                                          nsGui::Text::TRANSITION_COLOR_ALPHA,
                                                                          std::chrono::milliseconds(150), {255},
                                                                          std::chrono::milliseconds(50) * i,
                                                                          nsTransition::TransitionContract::MODE_FINITE_REVERSE));
    }
} // executeTitleHaloEffect()

#undef TITLEMENU
