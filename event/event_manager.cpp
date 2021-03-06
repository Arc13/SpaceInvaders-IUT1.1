/**
 * @file event_manager.cpp
 * @brief Le gestionnaire d'événement utilisateur
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#include "event_manager.h"

#define EVENTMANAGER nsEvent::EventManager

bool EVENTMANAGER::hasEvent()
{
    return m_eventQueue.size() > 0;
} // hasEvent()

void EVENTMANAGER::pushEvent(const Event_t &event)
{
    m_eventQueue.push(event);
} // pushEvent()

const nsEvent::Event_t EVENTMANAGER::pullEvent()
{
    // Copy the first element and then remove it from the queue
    const Event_t event = m_eventQueue.front();
    m_eventQueue.pop();
    return event;
} // pullEvent()

#undef EVENTMANAGER
