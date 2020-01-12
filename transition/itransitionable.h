/**
 * @file itransitionable.h
 * @brief Abstract class representing a transitionable element
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 10 janvier 2020
 */

#ifndef ITRANSITIONABLE_H
#define ITRANSITIONABLE_H

#include <vector>

namespace nsTransition
{

/**
 * @class ITransitionable
 * @brief An abstract class for any element that can have a transition between two states
 */
class ITransitionable
{
public:
    /**
     * @brief Destructor for the ITransitionable class
     * @fn virtual ~ITransitionable() {}
     */
    virtual ~ITransitionable() {}

    /**
     * @brief Get float values for the specified ID
     * @param[in] id: ID of the values to get
     * @param[in, out] values: Vector of values to be populated
     * @fn virtual void getValues(const int &id, std::vector<float> &values);
     */
    virtual void getValues(const int &id, std::vector<float> &values) = 0;

    /**
     * @brief Set float values for the specified ID
     * @param[in] id: ID of the values to set
     * @param[in] values: Vector of new values to be applied
     * @fn virtual void setValues(const int &id, const std::vector<float> &values);
     */
    virtual void setValues(const int &id, const std::vector<float> &values) = 0;
};

} // namespace nsTransition

#endif // ITRANSITIONABLE_H
