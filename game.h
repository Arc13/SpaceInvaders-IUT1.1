/*!
 * \file game.h
 * \brief Game entry point
 * \author SOLLIER Alexandre
 * \author LAUGIER Colin
 * \author PALATUIK Alison
 * \author AMBAUD Marc
 * \version 1.1
 * \date 28 décembre 2019
 */

#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <vector>

#include "graph/mingl.h"

/**
 * @brief Displays the game framerate to the window
 * @param[in] frameTime : Time that the frame took to render
 * @param[in, out] window : The window to print the framerate on
 * \fn void displayFramerate(const float &frameTime, MinGL &window);
 */
void displayFramerate(const std::chrono::microseconds &frameTime, MinGL &window);

/**
 * @brief Main function of the game
 * \fn void game();
 */
void game();

#endif // GAME_H
