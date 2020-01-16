/**
 * @file transition_types.h
 * @brief Type definitions for the Transition system
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 16 janvier 2020
 */

#ifndef TRANSITION_TYPES_H
#define TRANSITION_TYPES_H

#include <chrono>

namespace nsTransition
{

/**
 * @brief SystemDuration_t : Type definition representing a duration as nanoseconds, stored as float
 */
typedef std::chrono::duration<float, std::nano>            SystemDuration_t;

/**
 * @brief SystemTimePoint_t : Type definition representing a time point based on the system clock
 */
typedef std::chrono::time_point<std::chrono::steady_clock, SystemDuration_t> SystemTimePoint_t;

}

#endif // TRANSITION_TYPES_H
