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
 * @brief Elements représentant l'écran titre
 */
class TitleMenu : public IScreen
{
public:
    /**
     * @brief Constructeur pour la classe TitleMenu
     * @fn TitleMenu();
     */
    TitleMenu();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_transitionEngine : Une instance du moteur de transition
     */
    nsTransition::TransitionEngine m_transitionEngine;

    /**
     * @brief m_playButtonHovered : Actif si le curseur est sur le bouton Jouer
     */
    bool m_playButtonHovered;

    /**
     * @brief m_playButton : Le bouton pour démarrer le jeu
     */
    nsGui::Button m_playButton;

    /**
     * @brief m_topScoreButton : Le bouton pour afficher les top scores
     */
    nsGui::Button m_topScoreButton;

    /**
     * @brief Exécute la séquence d'apparition du titre
     * @fn void executeTitleAppearanceAnimation();
     */
    void executeTitleAppearanceAnimation();

    /**
     * @brief Exécute l'effet "halo" du titre
     * @fn void executeTitleHaloEffect();
     */
    void executeTitleHaloEffect();

    /**
     * @brief m_titleShown : Actif si le titre est affiché
     */
    bool m_titleShown;

    /**
     * @brief m_titleEnableAnimation : Actif si l'effet "halo" est autorisé
     */
    bool m_titleEnableAnimation;

    /**
     * @brief m_titleLastHaloTime : Temps depuis le dernier effet "halo"
     */
    nsTransition::SystemDuration_t m_titleLastHaloTime;

    /**
     * @brief m_titleText : Vecteur contentant toutes les lignes du titre
     */
    std::vector<nsGui::Text> m_titleText;
};

} // namespace nsScreen

#endif // SCREENMAINMENU_H
