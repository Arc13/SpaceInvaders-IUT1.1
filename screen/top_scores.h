/**
 * @file top_scores.h
 * @brief The screen showing the 10 top scores
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 18 janvier 2020
 */

#ifndef TOP_SCORES_H
#define TOP_SCORES_H

#include "iscreen.h"

#include "../gui/button.h"

namespace nsScreen {

/**
 * @class TopScores
 * @brief Ecran représentant le leaderboard
 */
class TopScores : public IScreen
{
public:
    TopScores();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_mainMenuButton : Bouton de retour vers le menu principal
     */
    nsGui::Button m_mainMenuButton;
};

}

#endif // TOP_SCORES_H
