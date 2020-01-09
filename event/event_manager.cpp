#include "event_manager.h"

#define EVENTMANAGER nsEvent::EventManager

bool EVENTMANAGER::hasEvent()
{
    return m_eventQueue.size() > 0;
}

void EVENTMANAGER::pushEvent(const Event_t &event)
{
    m_eventQueue.push(event);
}

const nsEvent::Event_t EVENTMANAGER::pullEvent()
{
    // Copy the first element and then remove it from the queue
    const Event_t event = m_eventQueue.front();
    m_eventQueue.pop();
    return event;
}

#undef EVENTMANAGER
