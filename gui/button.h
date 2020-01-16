/**
 * @file button.h
 * @brief An object providing a rectangle with centered text inside
 * @author SOLLIER Alexandre
 * @version 1.1
 * @date 16 janvier 2020
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "text.h"
#include "../graph/iminglinjectable.h"
#include "../transition/itransitionable.h"

namespace nsGui
{

/**
 * @class Button
 * @brief Provides a colored background with text inside, to be used as a button
 */
class Button : public IminGlInjectable, public nsTransition::ITransitionable
{
public:
    /**
     * @brief TransitionIds : List of every transition this object can execute
     */
    enum TransitionIds {
        TRANSITION_FIRST_RGB, /**< Transition for the first RGB color */
        TRANSITION_SECOND_RGB, /**< Transition for the second RGB color (for gradients) */
        TRANSITION_FIRST_ALPHA, /**< Transition for the first transparency */
        TRANSITION_SECOND_ALPHA, /**< Transition for the second transparency (for gradients) */
        TRANSITION_POSITION, /**< Transition for the position */
        TRANSITION_SIZE, /**< Transition for the size */
    };

    /**
     * @brief Constructor for the Button class, using this will produce a Button with a gradient
     * @param[in] text : Text inside this Button
     * @param[in] position : Position of the Button
     * @param[in] size : Size of the Button
     * @param[in] firstColor : First color of the Button
     * @param[in] secondColor : Second color of the Button
     * @fn Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor, const RGBAcolor &secondColor);
     */
    Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor, const RGBAcolor &secondColor);

    /**
     * @brief Constructor for the Button class, using this will produce a flat Button
     * @param[in] text : Text inside this Button
     * @param[in] position : Position of the Button
     * @param[in] size : Size of the Button
     * @param[in] firstColor : First color of the Button
     * @fn Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor);
     */
    Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor);

    virtual std::unique_ptr<IDrawable> clone() const override;

    virtual void getValues(const int &id, std::vector<float> &values) override;
    virtual void setValues(const int &id, const std::vector<float> &values) override;

    /**
     * @brief Gets the position of the button
     * @return A const reference to m_position
     * @fn const Vec2D& getPosition() const;
     */
    const Vec2D& getPosition() const;

    /**
     * @brief Sets the new position of the button
     * @param[in] position : The new position
     * @fn void setPosition(const Vec2D &position);
     */
    void setPosition(const Vec2D &position);

    /**
     * @brief Gets the size of the button
     * @return A const reference to m_size
     * @fn const Vec2D& getSize() const;
     */
    const Vec2D& getSize() const;

    /**
     * @brief Sets the new size of the button
     * @param[in] size : The new size
     * @fn void setSize(const Vec2D &size);
     */
    void setSize(const Vec2D &size);

protected:
    virtual void draw(MinGL &window) override;

private:
    /**
     * @brief m_buttonText : The Text object of this Button
     */
    Text m_buttonText;

    /**
     * @brief m_firstColor : The first, leftmost color
     */
    RGBAcolor m_firstColor;

    /**
     * @brief m_secondColor : The second, rightmost color
     */
    RGBAcolor m_secondColor;

    /**
     * @brief m_position : The position of this Button
     */
    Vec2D m_position;

    /**
     * @brief m_position : The size of this Button
     */
    Vec2D m_size;
};

} // namespace nsGui

#endif // BUTTON_H
