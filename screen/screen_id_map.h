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
 * @brief Convertit un ID d'écran vers un pointeur unique
 */
class ScreenIdMap
{
public:
    /**
     * @brief Récupère un pointeur unique d'une classe dérivée d'IScreen depuis un ID
     * @param[in] screenId : L'ID de l'écran
     * @return Un pointeur unique vers la classe dérivée d'IScreen
     * @fn static std::unique_ptr<IScreen> getScreenFromId(const ScreenIdentifiers &screenId);
     */
    static std::unique_ptr<IScreen> getScreenFromId(const ScreenIdentifiers &screenId);
};

} // namespace nsScreen

#endif // SCREEN_ID_MAP_H
