/**
 * @file event_manager.h
 * @brief The event manager for user inputs
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <queue>

#include "event.h"

namespace nsEvent {

/**
 * \class EventManager
 * \brief Manages a queue of incoming events
 */
class EventManager
{
public:
    /**
     * @brief Checks if there's an event to be pulled
     * @return Whether the queue has one or more element
     * @fn bool hasEvent();
     */
    bool hasEvent();

    /**
     * @brief Pushes a new event to the queue
     * @param[in] event : Event to push
     * @fn void pushEvent(const Event_t &event);
     */
    void pushEvent(const Event_t &event);

    /**
     * @brief Pulls the oldest event, and then removes it from the queue
     * @return A copy of the oldest event
     * @fn const Event_t pullEvent();
     */
    const Event_t pullEvent();

private:
    /**
     * @brief m_eventQueue : Queue holding incoming events
     */
    std::queue<Event_t> m_eventQueue;
};

} // namespace nsEvent

#endif // EVENTMANAGER_H
