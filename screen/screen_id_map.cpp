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
}

#undef SCREENIDMAP
