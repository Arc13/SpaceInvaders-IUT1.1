/**
 * @file difficulty.hpp
 * @brief Provides multiple difficulties to the game
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 17 janvier 2020
 */

#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <map>

#include "../tools/myexception.h"

namespace nsGame {

/**
 * @struct Difficulty
 * @brief Possède des données de difficulté pour une instance de MainGame
 */
struct Difficulty {
    /**
     * @brief Constructeur pour la structure Difficulty
     * @param[in] id_ : ID de cette Difficulty
     * @param[in] frequencyModifier_ : Multiplicateur pour les différentes fréquences en-jeu
     * @param[in] lifeCount_ : Nombre de vie du joueur
     * @param[in] scoreModifier_ : Multiplicateur pour le score
     * @fn Difficulty(const unsigned &id_, const float &frequencyModifier_,
               const unsigned &lifeCount_, const float &scoreModifier_);
     */
    Difficulty(const unsigned &id_, const float &frequencyModifier_,
               const unsigned &lifeCount_, const float &scoreModifier_)
        : id(id_)
        , frequencyModifier(frequencyModifier_)
        , lifeCount(lifeCount_)
        , scoreModifier(scoreModifier_) {}

    const unsigned id; /**< ID de cette difficulté */
    const float frequencyModifier; /**< Multiplicateur pour les différentes fréquences en-jeu */
    const unsigned lifeCount; /**< Nombre de vie du joueur */
    const float scoreModifier; /**< Multiplicateur pour le score */
};

/**
 * @brief La difficulté normale, avec tout les multiplicateur a 1.
 */
const Difficulty KNormalDifficulty(0, 1, 3, 1);

/**
 * @brief La difficulté facile, avec des fréquences basses et un grand nombre de vie,
 * mais un multiplicateur de score bas.
 */
const Difficulty KEasyDifficulty(1, 1.5, 5, 0.4);

/**
 * @brief La difficulté difficilé, avec des fréquences hautes et un petit nombre de vie,
 * mais un multiplicateur de score haut.
 */
const Difficulty KHardDifficulty(2, 0.5, 1, 2);

/**
 * @brief La difficulté insane, avec des fréquences très hautes et une seule vie,
 * mais un multiplicateur de score très grand.
 */
const Difficulty KInsaneDifficulty(3, 0.3, 0, 3);

}

#endif // DIFFICULTY_H
