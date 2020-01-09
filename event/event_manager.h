/*!
 * \file event_manager.h
 * \brief The event manager for user inputs
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 09 janvier 2020
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <queue>

#include "event.h"

namespace Event {

class EventManager
{
public:
    EventManager();

    bool hasEvent();
    void pushEvent(const Event &event);
    const Event pullEvent();

private:
    std::queue<Event> m_eventQueue;
};

} // namespace Event

#endif // EVENTMANAGER_H
