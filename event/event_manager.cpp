#include "event_manager.h"

namespace Event {

EventManager::EventManager()
{

}

bool EventManager::hasEvent()
{
    return m_eventQueue.size() > 0;
}

void EventManager::pushEvent(const Event &event)
{
    m_eventQueue.push(event);
}

const Event EventManager::pullEvent()
{
    const Event event = m_eventQueue.front();
    m_eventQueue.pop();
    return event;
}

} // namespace Event
