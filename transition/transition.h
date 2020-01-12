/**
 * @file transition.h
 * @brief A playing transition
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 10 janvier 2020
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include "transition_contract.h"

/**
 * @namespace nsTransition
 * @brief Namespace for the transition engine and its components
 */
namespace nsTransition
{

/**
 * @class Transition
 * @brief A class containing a TransitionContract that is being played
 */
class Transition : public TransitionContract
{
public:
    /**
     * @brief Constructor for the Transition class
     * @param[in] contract : Contract used to initialise this Transition
     * @fn Transition(const TransitionContract &contract);
     */
    Transition(const TransitionContract &contract);

    /**
     * @brief Returns the amount of time elapsed for this Transition
     * @return A const reference to m_elapsed
     * @fn const SystemDuration_t& getElapsed() const;
     */
    const SystemDuration_t& getElapsed() const;

    /**
     * @brief Sets the amount of time elapsed for this Transition,
     * and then updates the values being transitioned
     * @param[in] elapsed : The new elapsed time
     * @fn void setElapsed(const SystemDuration_t &elapsed);
     */
    void setElapsed(const SystemDuration_t &elapsed);

    /**
     * @brief Adds a duration to the current elapsed time
     * @param[in] addedTime : The time to add to the current elapsed time
     * @fn void addToElapsed(const SystemDuration_t &addedTime);
     */
    void addToElapsed(const SystemDuration_t &addedTime);

    /**
     * @brief Returns whether this transition is playing backwards
     * @return A const reference to m_reverse
     * @fn const bool& isReversed() const;
     */
    const bool& isReversed() const;

    /**
     * @brief Marks this instance of Transition as finished
     * @fn void finish();
     */
    void finish();

    /**
     * @brief Returns whether this instance of Transition is marked as finished
     * @return A const reference to m_finished
     * @fn const bool& isFinished() const;
     */
    const bool& isFinished() const;

private:
    /**
     * @brief m_startTime : Holds the time when this transition started
     */
    SystemTimePoint_t m_startTime;

    /**
     * @brief m_elapsed : Holds the elapsed time since this transition started
     */
    SystemDuration_t m_elapsed;

    /**
     * @brief m_reverse : Set to true if this transition is playing backwards
     * i.e. playing from the end to the beginning values
     */
    bool m_reverse;

    /**
     * @brief m_finished : Whether this Transition should be considered finished
     * The TransitionEngine would remove such Transition from its list
     */
    bool m_finished;

    /**
     * @brief Computes and sets the new values to the target,
     * based from the elapsed time, the duration and the start time
     * @fn void updateValues();
     */
    void updateValues();

    /**
     * @brief Called whenever this Transition has reached the destination values
     * @fn void handleEndlife();
     */
    void handleEndlife();
};

} // namespace nsTransition

#endif // TRANSITION_H
