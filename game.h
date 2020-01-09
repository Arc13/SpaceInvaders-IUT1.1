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

#define STAR_COUNT 300
#define STAR_LIT_PROBABILITY 0.05

#include <chrono>
#include <vector>

#include "graph/mingl.h"

/**
 * @brief Displays the game framerate to the window
 * @param[in] FrameTime : Time that the frame took to render
 * @param[in/out] Window : The window to print the framerate on
 * \fn void displayFramerate(const std::chrono::milliseconds FrameTime, MinGL &Window);
 */
void displayFramerate(const std::chrono::milliseconds FrameTime, MinGL &Window);

/**
 * @brief Main function of the game
 * \fn void Game();
 */
void Game();

#endif // GAME_H
