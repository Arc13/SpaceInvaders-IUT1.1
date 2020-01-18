/**
 * @file end_game.h
 * @brief The screen shown at the end of the game
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 18 janvier 2020
 */

#ifndef END_GAME_H
#define END_GAME_H

#include "iscreen.h"

#include "../gui/button.h"
#include "../gui/text.h"

namespace nsScreen {

class EndGame : public IScreen
{
public:
    EndGame();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    bool m_enteringName;

    std::string m_name;
    nsGui::Text m_nameTitle;
    nsGui::Text m_nameText;

    nsGui::Button m_mainMenuButton;
    nsGui::Button m_topScoreButton;

    bool m_scoreSaved;
    nsGui::Text m_scoreSavedText;

    bool m_hasWon;
    unsigned m_score;
};

}

#endif // END_GAME_H
