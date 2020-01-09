#include "screen_id_map.h"

#include "screen_main_menu.h"

#include "../tools/myexception.h"

std::unique_ptr<IScreen> ScreenIdMap::getScreenFromId(const ScreenIdentifiers &screenId)
{
    switch (screenId) {
    case ScreenIdentifiers::MainMenu:
        return std::unique_ptr<IScreen>(new ScreenMainMenu());

    case ScreenIdentifiers::None:
    default:
        throw MyException(nsUtil::kScreenNotFound);
    }
}
