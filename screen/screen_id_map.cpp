/**
 * @file screen_id_map.cpp
 * @brief Provides mapping between ScreenIdentifiers and IScreen derived classes
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#include "screen_id_map.h"

#include "main_menu.h"

#include "../tools/myexception.h"

#define SCREENIDMAP nsScreen::ScreenIdMap

std::unique_ptr<nsScreen::IScreen> SCREENIDMAP::getScreenFromId(const nsScreen::ScreenIdentifiers &screenId)
{
    // Check the ID and return the right Screen
    switch (screenId)
    {
        case ScreenIdentifiers::ID_MainMenu:
            return std::unique_ptr<IScreen>(new nsScreen::MainMenu());

        case ScreenIdentifiers::ID_None:
        default:
            throw MyException(nsUtil::kScreenNotFound);
    }
} // getScreenFromId()

#undef SCREENIDMAP
