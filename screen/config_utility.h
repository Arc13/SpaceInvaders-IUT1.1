/**
 * @file config_utility.h
 * @brief The configuration screen definition
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 18 janvier 2020
 */

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

/**
 * @class ConfigUtility
 * @brief Ecran représentant le panneau de configuration utilisateur
 */
class ConfigUtility : public IScreen
{
public:
    /**
     * @brief Constructeur pour la classe ConfigUtility
     * @fn ConfigUtility();
     */
    ConfigUtility();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_configuration : Tableau de configuration de la partie
     */
    nsConfig::TableauCommande m_configuration;

    /**
     * @brief m_screenTitle : Titre de cet écran
     */
    nsGui::Text m_screenTitle;

    /**
     * @brief m_mainMenuButton : Bouton de retour vers le menu principal
     */
    nsGui::Button m_mainMenuButton;

    /**
     * @brief Récupère la difficulté en tant que chiffre
     * @return La difficulté actuelle
     * @fn unsigned getDifficulty();
     */
    unsigned getDifficulty();

    /**
     * @brief Définit la difficulté du jeu
     * @param[in] difficulty : Nouvelle difficulté du jeu
     * @fn void setDifficulty(const unsigned &difficulty);
     */
    void setDifficulty(const unsigned &difficulty);

    /**
     * @brief Mets à jour le texte pour refléter la difficulté actuelle
     * @fn void updateDifficultyText();
     */
    void updateDifficultyText();

    /**
     * @brief m_difficultyTitle : Titre de la section difficulté
     */
    nsGui::Text m_difficultyTitle;

    /**
     * @brief m_difficultyText : Texte contenant la difficulté actuelle
     */
    nsGui::Text m_difficultyText;

    /**
     * @brief m_difficultyTextBackground : Fond transparent pour m_difficultyText
     */
    Rectangle m_difficultyTextBackground;

    /**
     * @brief m_difficultyDecreaseButton : Bouton pour baisser la difficulté
     */
    nsGui::Button m_difficultyDecreaseButton;

    /**
     * @brief m_difficultyDecreaseButton : Bouton pour augmenter la difficulté
     */
    nsGui::Button m_difficultyIncreaseButton;

    /**
     * @brief Control : Liste de tout les contrôles personnalisables
     */
    enum Control {
        CONTROL_NONE, /**< Ne représente aucun contrôle */

        CONTROL_RIGHT, /**< Contrôle de déplacement Droite */
        CONTROL_LEFT, /**< Contrôle de déplacement Gauche */
        CONTROL_SHOOT, /**< Contrôle de Tir */
    };

    /**
     * @brief Convertit un caractère en chaine de caractère, avec un nom explicite si besoin
     * @param[in] key : Le caractère a convertir
     * @return Le caractère en tant que string, ou le nom de ce caractère
     * @fn std::string getKeyAsText(const char &key);
     */
    std::string getKeyAsText(const char &key);

    /**
     * @brief Mets à jour le texte d'un des contrôles pour refléter le contrôle actuel
     * @param[in] control : Le contrôle a mettre a jour
     * @fn void updateControlText(const Control &control);
     */
    void updateControlText(const Control &control);

    /**
     * @brief Désélectionne le contrôle actuellement sélectionné
     * @fn void deselectControl();
     */
    void deselectControl();

    /**
     * @brief Selectionne un contrôle pour pouvoir le modifier
     * @param[in] control : Le contrôle a sélectionner
     * @fn void selectControl(const Control &control);
     */
    void selectControl(const Control &control);

    /**
     * @brief Assigne une touche a un contrôle
     * @param[in] control : Le contrôle a modifier
     * @param[in] key : La touche a assigner
     * @fn void assignControlToKey(const Control &control, const char &key);
     */
    void assignControlToKey(const Control &control, const char &key);

    /**
     * @brief m_selectedControl : Contrôle sélectionné, qui est en cours de modification
     */
    Control m_selectedControl;

    /**
     * @brief m_controlsTitle : Titre de la section contrôle
     */
    nsGui::Text m_controlsTitle;

    /**
     * @brief m_controlsRight : Texte contenant la touche du contrôle Droite
     */
    nsGui::Text m_controlsRight;

    /**
     * @brief m_controlsLeft : Texte contenant la touche du contrôle Gauche
     */
    nsGui::Text m_controlsLeft;

    /**
     * @brief m_controlsShoot : Texte contenant la touche du contrôle Tir
     */
    nsGui::Text m_controlsShoot;

    /**
     * @brief m_transitionEngine : Une instance du moteur de transition
     */
    nsTransition::TransitionEngine m_transitionEngine;
};

}

#endif // CONFIG_UTILITY_H
