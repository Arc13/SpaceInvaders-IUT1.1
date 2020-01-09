#include "iscreen.h"

#define SCREENIDENTIFIERS nsScreen::IScreen

nsScreen::ScreenIdentifiers SCREENIDENTIFIERS::getRequestedScreenChange() const
{
    return m_screenChange;
}

void SCREENIDENTIFIERS::requestScreenChange(const ScreenIdentifiers &screenId)
{
    m_screenChange = screenId;
}

#undef SCREENIDENTIFIERS
