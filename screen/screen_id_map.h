/**
 * @file screen_id_map.h
 * @brief Provides mapping between ScreenIdentifiers and IScreen derived classes
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef SCREEN_ID_MAP_H
#define SCREEN_ID_MAP_H

#include <memory>

#include "iscreen.h"
#include "screen_identifiers.h"

namespace nsScreen {

/**
 * @class ScreenIdMap
 * @brief Converts Screen ID to a Screen
 */
class ScreenIdMap
{
public:
    /**
     * @brief Gets a pointer to an IScreen derived class from a screen ID
     * @param[in] screenId : The ID of the screen to get
     * @return A unique pointer to the IScreen derived class
     * @fn static std::unique_ptr<IScreen> getScreenFromId(const ScreenIdentifiers &screenId);
     */
    static std::unique_ptr<IScreen> getScreenFromId(const ScreenIdentifiers &screenId);
};

} // namespace nsScreen

#endif // SCREEN_ID_MAP_H
