/**
 * @file idrawable.h
 * @brief An interface for drawable objects
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 08 janvier 2020
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>

class MinGL;

/**
 * @class IDrawable
 * @brief Interface for a drawable object
 */
class IDrawable
{
public:
    /**
     * @brief Destructor for the IDrawable class
     * @fn virtual ~IDrawable() {}
     */
    virtual ~IDrawable() {}

    /**
     * @brief Signature for the function to clone the object
     * @return A pointer to the cloned object
     * @fn virtual std::unique_ptr<IDrawable> clone() const;
     */
    virtual std::unique_ptr<IDrawable> clone() const = 0;

    /**
     * @brief Signature for the function to draw the object
     * @param[in] window : The target window
     * @fn virtual void draw(MinGL &window);
     */
    virtual void draw(MinGL &window) = 0;
};

#endif // DRAWABLE_H
