/*!
 * \file idrawable.h
 * \brief An interface for drawable objects
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 08 janvier 2020
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>

class IDrawable
{
public:
    /**
     * @brief Constructor for the IDrawable class
     * @fn virtual ~IDrawable() {}
     */
    virtual ~IDrawable() {}

    /**
     * @brief Signature for the function to clone the object
     * @fn virtual std::unique_ptr<IDrawable> clone() const;
     */
    virtual std::unique_ptr<IDrawable> clone() const = 0;

    /**
     * @brief Signature for the function to draw the object
     * @fn virtual void Draw() const;
     */
    virtual void Draw() const = 0;
};

#endif // DRAWABLE_H
