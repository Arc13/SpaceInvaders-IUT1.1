/**
 * @file difficulty.hpp
 * @brief Fourni plusieurs difficultés au jeu
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 17 janvier 2020
 */

#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <vector>

#include "../tools/myexception.h"

namespace nsGame {

/**
 * @struct Difficulty
 * @brief Possède des données de difficulté pour une instance de MainGame
 */
struct Difficulty {
    float frequencyModifier; /**< Multiplicateur pour les différentes fréquences en-jeu */
    unsigned lifeCount; /**< Nombre de vie du joueur */
    float scoreModifier; /**< Multiplicateur pour le score */

    /**
     * @brief Constructeur pour la structure Difficulty
     * @param[in] id_ : ID de cette Difficulty
     * @param[in] frequencyModifier_ : Multiplicateur pour les différentes fréquences en-jeu
     * @param[in] lifeCount_ : Nombre de vie du joueur
     * @param[in] scoreModifier_ : Multiplicateur pour le score
     * @fn Difficulty(const unsigned &id_, const float &frequencyModifier_,
               const unsigned &lifeCount_, const float &scoreModifier_);
     */
    Difficulty(const float &frequencyModifier_,
               const unsigned &lifeCount_, const float &scoreModifier_)
        : frequencyModifier(frequencyModifier_)
        , lifeCount(lifeCount_)
        , scoreModifier(scoreModifier_) {}
};

/**
 * @brief La difficulté normale, avec tout les multiplicateur a 1.
 */
const Difficulty KNormalDifficulty(1, 3, 1);

/**
 * @brief La difficulté facile, avec des fréquences basses et un grand nombre de vie,
 * mais un multiplicateur de score bas.
 */
const Difficulty KEasyDifficulty(1.5, 5, 0.4);

/**
 * @brief La difficulté difficilé, avec des fréquences hautes et un petit nombre de vie,
 * mais un multiplicateur de score haut.
 */
const Difficulty KHardDifficulty(0.5, 1, 2);

/**
 * @brief La difficulté insane, avec des fréquences très hautes et une seule vie,
 * mais un multiplicateur de score très grand.
 */
const Difficulty KInsaneDifficulty(0.3, 0, 3);

/**
 * @brief PredefinedDifficulty : Liste de toutes les difficultés prédéfinies
 */
enum PredefinedDifficulty {
    DIFFICULTY_EASY, /**< Difficulté facile */
    DIFFICULTY_NORMAL, /**< Difficulté normale */
    DIFFICULTY_HARD, /**< Difficulté difficile */
    DIFFICULTY_INSANE, /**< Difficulté impossible */
};

/**
 * @brief KDifficultyName : Vecteur contenant le nom des difficultés prédéfinies
 */
const std::vector<std::string> KDifficultyName = {
    "Facile",
    "Normal",
    "Difficile",
    "Impossible"
};

}

#endif // DIFFICULTY_H
