/*!
 * \file iscreen.h
 * \brief Interface for a screen taking the entire window
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 09 janvier 2020
 */

#ifndef ISCREEN_H
#define ISCREEN_H

#include <memory>

#include "screen_identifiers.h"

#include "../event/event.h"
#include "../graph/mingl.h"

class IScreen
{
public:
    virtual ~IScreen() {}

    virtual void processEvent(const Event::Event &event) = 0;
    virtual void update(const float &delta) = 0;
    virtual void draw(MinGL &window) = 0;

    ScreenIdentifiers getRequestedScreenChange() const;

protected:
    void requestScreenChange(const ScreenIdentifiers &screenId);

private:
    ScreenIdentifiers m_screenChange = ScreenIdentifiers::None;
};

#endif // ISCREEN_H
