/**
 * @file transition_engine.h
 * @brief An engine for the transition system
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 10 janvier 2020
 */

#ifndef TRANSITION_ENGINE_H
#define TRANSITION_ENGINE_H

#include <chrono>
#include <memory>
#include <list>

#include "transition.h"

namespace nsTransition
{

/**
 * @class TransitionEngine
 * @brief A class implementing an engine to support multiple transitions at once
 */
class TransitionEngine
{
public:
    /**
     * @brief Updates every Transition in the list
     * @param[in] delta : Time that the previous frame took to render
     * @fn void update(const std::chrono::microseconds &delta);
     *
     * This function adds the value of delta to the elapsed time of the transitions,
     * and checks for any finished transition to remove.
     */
    void update(const std::chrono::microseconds &delta);

    /**
     * @brief Starts a contract
     * @param[in] contract : Transition contract to start in this engine
     * @fn void startContract(const TransitionContract &contract);
     */
    void startContract(const TransitionContract &contract);

private:
    /**
     * @brief TransitionVector_t : Type definition representing a list of Transition
     */
    typedef std::list<Transition> TransitionVector_t;

    /**
     * @brief m_transitionList : The list of transition this engine is taking care of
     */
    TransitionVector_t m_transitionList;
};

} // namespace nsTransition

#endif // TRANSITION_ENGINE_H
