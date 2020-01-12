/**
 * @file transition_contract.h
 * @brief Parameters for a transition
 * @author SOLLIER Alexandre
 * @version 1.1
 * @date 10 janvier 2020
 */

#ifndef TRANSITION_CONTRACT_H
#define TRANSITION_CONTRACT_H

#include <chrono>
#include <functional>
#include <vector>

#include "itransitionable.h"

namespace nsTransition
{

/**
 * @class TransitionContract
 * @brief A class containing parameters to create a Transition
 */
class TransitionContract
{
public:
    /**
     * @brief SystemTimePoint_t : Type definition representing a time point based on the system clock
     */
    typedef std::chrono::time_point<std::chrono::system_clock> SystemTimePoint_t;

    /**
     * @brief SystemDuration_t : Type definition representing a duration as nanoseconds, stored as float
     */
    typedef std::chrono::duration<float, std::nano>            SystemDuration_t;

    /**
     * @brief TransitionMode : List of all Transition modes
     */
    enum TransitionMode {
        MODE_FINITE, /**< This mode will mark the Transition as finished when the transitioned values reached the destination */
        MODE_LOOP, /**< This mode will reset the transitioned values to the beginning values, and then start over */
        MODE_LOOP_SMOOTH, /**< This mode will reverse the Transition each time it reached the destination */
    };

    /**
     * @brief Constructor for the TransitionContract class
     * @param[in, out] target : A reference to a derived class of ITransitionable that will be transitioned
     * @param[in] id : The ID of the values to apply a transition on
     * @param[in] duration : The duration the transition has to play
     * @param[in] destination : The end values
     * @param[in] transitionMode : The mode this transition should play, defaults to a finite transition
     * @fn TransitionContract(ITransitionable& target, const int &id,
                       const std::chrono::seconds &duration, const std::vector<float> &destination,
                       const TransitionMode &transitionMode = TransitionMode::MODE_FINITE);
     */
    TransitionContract(ITransitionable& target, const int &id,
                       const std::chrono::seconds &duration, const std::vector<float> &destination,
                       const TransitionMode &transitionMode = TransitionMode::MODE_FINITE);

    /**
     * @brief Returns the transition ID, that will be used by the target to
     * know which values has to be updated
     * @return A const reference to m_id
     * @fn const int& getId() const;
     */
    const int& getId() const;

    /**
     * @brief Returns the transition ID, that will be used by the target to
     * know which values has to be updated
     * @return A const reference to m_target
     * @fn const ITransitionable& getTarget() const;
     */
    const ITransitionable& getTarget() const;

    /**
     * @brief Returns the transition mode
     * @return A const reference to m_transitionMode
     * @fn const TransitionMode& getTransitionMode() const;
     */
    const TransitionMode& getTransitionMode() const;

    /**
     * @brief Returns the values at the start of the transition
     * @return A const reference to m_beginning
     * @fn const std::vector<float>& getBeginning() const;
     */
    const std::vector<float>& getBeginning() const;

    /**
     * @brief Returns the destination values
     * @return A const reference to m_destination
     * @fn const std::vector<float>& getDestination() const;
     */
    const std::vector<float>& getDestination() const;

    /**
     * @brief Returns the duration of the transition
     * @return A const reference to m_duration
     * @fn const SystemDuration_t& getDuration() const;
     */
    const SystemDuration_t& getDuration() const;

    /**
     * @brief Sets the function to be called when the transition reaches the destination
     * @param[in] callback : The function to be called
     * @fn void setDestinationCallback(const std::function<void()> &callback);
     */
    void setDestinationCallback(const std::function<void()> &callback);

protected:
    /**
     * @brief m_id : The ID of the transition
     *
     * This is only meaningful for the target, because it knows which ID correspond to which values.
     * Thus, the ID is never directly used by TransitionContract nor Transition, and is merely passed to the target when required.
     */
    const int m_id;

    /**
     * @brief m_target : A reference to an instance of a derived class of ITransitionable
     *
     * This is the target of the transition, so the transition will be applied to this element.
     */
    ITransitionable& m_target;

    /**
     * @brief m_transitionMode : The mode used for the transition
     *
     * Check the TransitionMode enumeration values for more informations.
     */
    const TransitionMode m_transitionMode;

    /**
     * @brief m_beginning : Contains the value at the start of the transition
     */
    std::vector<float> m_beginning;

    /**
     * @brief m_destination : Contains the value at the end of the transition
     *
     * Those are the targeted values. When the transition ends, those values should reflect the current values of the targeted element.
     */
    const std::vector<float> m_destination;

    /**
     * @brief m_duration : The duration of the transition
     */
    SystemDuration_t m_duration;

    /**
     * @brief m_duration : A pointer to the function to be called when the transition reaches the destination
     */
    std::function<void()> m_destinationCallback;
};

} // namespace nsTransition

#endif // TRANSITION_CONTRACT_H
