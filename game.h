/**
 * @file game.h
 * @brief Point d'entrée du jeu
 * @author SOLLIER Alexandre
 * @author LAUGIER Colin
 * @author PALATUIK Alison
 * @author AMBAUD Marc
 * @version 1.2
 * @date 28 décembre 2019
 */

#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <vector>

#include "graph/mingl.h"

/**
 * @brief Affiche le framerate dans la fenêtre
 * @param[in] frameTime : Temps que l'image a mis pour faire son rendu
 * @param[in, out] window : La fenêtre où afficher l'information
 * @fn void displayFramerate(const float &frameTime, MinGL &window);
 */
void displayFramerate(const std::chrono::microseconds &frameTime, MinGL &window);

/**
 * @brief Fonction principale du jeu
 * @fn void game();
 */
void game();

#endif // GAME_H
