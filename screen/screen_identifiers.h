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
 * @brief ScreenIdentifiers : List of all Screen identifiers
 */
enum ScreenIdentifiers {
    ID_None, /**< No screen */

    ID_TitleMenu, /**< The title screen */
    ID_MainGame, /**< The game screen */
};

} // namespace nsScreen

#endif // SCREEN_IDENTIFIERS_H
