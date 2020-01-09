/**
 * @file iscreen.h
 * @brief Interface for a screen taking the entire window
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef ISCREEN_H
#define ISCREEN_H

#include <memory>

#include "screen_identifiers.h"

#include "../event/event.h"
#include "../graph/mingl.h"
/**
 * @namespace nsScreen
 * @brief Namespace for related sets of GUI element
 */
namespace nsScreen {

/**
 * @class IScreen
 * @brief Interface for a screen taking the entire window
 */
class IScreen
{
public:
    /**
     * @brief Destructor for the IScreen class
     * @fn virtual ~IScreen() {}
     */
    virtual ~IScreen() {}

    /**
     * @brief Called whenever an user input happens
     * @param[in] event : The event that just happened
     * @fn virtual void processEvent(const nsEvent::Event &event);
     */
    virtual void processEvent(const nsEvent::Event_t &event) = 0;

    /**
     * @brief Called every frame to update screen's logic
     * @param[in] delta : Time that the previous frame took to render
     * @fn virtual void update(const float &delta);
     */
    virtual void update(const float &delta) = 0;

    /**
     * @brief Called every frame to draw the screen
     * @param[in, out] window : The window to draw to
     * @fn virtual void draw(MinGL &window);
     */
    virtual void draw(MinGL &window) = 0;

    /**
     * @brief Gets the ID of the new screen that this screen requested to switch to
     * @fn ScreenIdentifiers getRequestedScreenChange() const;
     */
    ScreenIdentifiers getRequestedScreenChange() const;

protected:
    /**
     * @brief Sets the ID of the new screen to switch to
     * @param[in] screenId : The new screen ID
     * @fn void requestScreenChange(const ScreenIdentifiers &screenId);
     */
    void requestScreenChange(const ScreenIdentifiers &screenId);

private:
    /**
     * @brief m_screenChange : Screen to switch to
     */
    ScreenIdentifiers m_screenChange = ScreenIdentifiers::ID_None;
};

} // namespace nsScreen

#endif // ISCREEN_H
