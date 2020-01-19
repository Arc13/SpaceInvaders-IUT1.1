/**
 * @file iscreen.cpp
 * @brief Interface pour un écran
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#include "iscreen.h"

#define SCREENIDENTIFIERS nsScreen::IScreen

const nsScreen::ScreenIdentifiers& SCREENIDENTIFIERS::getRequestedScreenChange() const
{
    return m_screenChange;
} // getRequestedScreenChange()

void SCREENIDENTIFIERS::requestScreenChange(const ScreenIdentifiers &screenId)
{
    m_screenChange = screenId;
} // requestScreenChange()

#undef SCREENIDENTIFIERS
