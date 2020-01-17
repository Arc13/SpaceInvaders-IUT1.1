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

#include "event.hpp"

namespace nsEvent {

/**
 * @class EventManager
 * @brief Gère une queue d'événement entrants
 */
class EventManager
{
public:
    /**
     * @brief Vérifie si un événement doit être traité
     * @return Si la queue possède au moins un élément
     * @fn bool hasEvent();
     */
    bool hasEvent();

    /**
     * @brief Pousse un nouvel événement dans la queue
     * @param[in] event : Evénement a pousser
     * @fn void pushEvent(const Event_t &event);
     */
    void pushEvent(const Event_t &event);

    /**
     * @brief Tire l'événement le plus ancien, et l'enlève de la queue
     * @return Une copie du plus ancien événement
     * @fn const Event_t pullEvent();
     */
    const Event_t pullEvent();

private:
    /**
     * @brief m_eventQueue : Queue possèdant des événement entrants
     */
    std::queue<Event_t> m_eventQueue;
};

} // namespace nsEvent

#endif // EVENTMANAGER_H
