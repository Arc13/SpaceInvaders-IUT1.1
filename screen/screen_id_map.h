#ifndef SCREEN_ID_MAP_H
#define SCREEN_ID_MAP_H

#include <memory>

#include "iscreen.h"
#include "screen_identifiers.h"

class ScreenIdMap
{
public:
    static std::unique_ptr<IScreen> getScreenFromId(const ScreenIdentifiers &screenId);
};

#endif // SCREEN_ID_MAP_H
