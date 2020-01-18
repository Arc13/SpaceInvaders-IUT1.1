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

/**
 * @class EndGame
 * @brief Ecran représentant la fin du jeu
 */
class EndGame : public IScreen
{
public:
    /**
     * @brief Constructeur pour la classe EndGame
     * @fn EndGame();
     */
    EndGame();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_enteringName : Représente si l'utilisateur est en train d'entrer son nom
     * ou si il peut quitter l'écran
     */
    bool m_enteringName;

    /**
     * @brief m_name : Contient le nom du joueur, au fur et a mesure qu'il le tape
     */
    std::string m_name;

    /**
     * @brief m_nameTitle : Texte d'indication pour entrer son nom
     */
    nsGui::Text m_nameTitle;

    /**
     * @brief m_nameTitle : Texte affichant le nom du joueur en temps réel
     */
    nsGui::Text m_nameText;

    /**
     * @brief m_mainMenuButton : Bouton de retour vers le menu principal
     */
    nsGui::Button m_mainMenuButton;

    /**
     * @brief m_topScoreButton : Bouton pour afficher le leaderboard
     */
    nsGui::Button m_topScoreButton;

    /**
     * @brief m_scoreSaved : Représente si le score a été sauvegardé au classement
     */
    bool m_scoreSaved;

    /**
     * @brief m_scoreSavedText : Texte affichant le score du joueur ainsi qu'un texte de motivation
     */
    nsGui::Text m_scoreSavedText;

    /**
     * @brief m_hasWon : Représente la victoire du joueur lors de la dernière session de jeu
     */
    bool m_hasWon;

    /**
     * @brief m_hasWon : Représente le score du joueur lors de la dernière session de jeu
     */
    unsigned m_score;
};

}

#endif // END_GAME_H
