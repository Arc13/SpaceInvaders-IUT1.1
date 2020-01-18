/**
 * @file screen_identifiers.h
 * @brief Identifiers for the various screens
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef SCREEN_IDENTIFIERS_H
#define SCREEN_IDENTIFIERS_H

namespace nsScreen {

/**
 * @brief ScreenIdentifiers : Liste de tout les identificateurs d'écran
 */
enum ScreenIdentifiers {
    ID_None, /**< Aucun écran */

    ID_TitleMenu, /**< L'écran titre */
    ID_TopScores, /**< L'écran des top scores */

    ID_MainGame, /**< L'écran de jeu */
    ID_EndGame, /**< L'écran d'enregistrement du score */
};

} // namespace nsScreen

#endif // SCREEN_IDENTIFIERS_H
