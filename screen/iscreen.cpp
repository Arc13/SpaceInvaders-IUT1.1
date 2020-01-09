#include "iscreen.h"

ScreenIdentifiers IScreen::getRequestedScreenChange() const
{
    return m_screenChange;
}

void IScreen::requestScreenChange(const ScreenIdentifiers &screenId)
{
    m_screenChange = screenId;
}

