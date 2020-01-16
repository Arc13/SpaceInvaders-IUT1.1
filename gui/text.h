/**
 * @file text.h
 * @brief Text that can be displayed to a MinGL Window
 * @author SOLLIER Alexandre
 * @version 1.1
 * @date 28 décembre 2019
 */

#ifndef GUITEXT_H
#define GUITEXT_H

#include "../tools/glut_font.h"
#include "../graph/iminglinjectable.h"
#include "../transition/itransitionable.h"

/**
 * @namespace nsGui
 * @brief Namespace for complex GUI elements
 */
namespace nsGui {

/**
 * @class Text
 * @brief Manages the drawing of a text
 */
class Text : public IminGlInjectable, public nsTransition::ITransitionable
{
public:
    /**
     * @brief TransitionIds : List of every transition this object can execute
     */
    enum TransitionIds {
        TRANSITION_COLOR_RGB, /**< Transition for the RGB color */
        TRANSITION_COLOR_ALPHA, /**< Transition for the transparency */
        TRANSITION_POSITION, /**< Transition for the position */
    };

    /**
     * @brief VerticalAlignment : List of every supported vertical alignment
     */
    enum VerticalAlignment {
        ALIGNV_TOP, /**< The text will be vertically aligned to the top */
        ALIGNV_CENTER, /**< The text will be vertically aligned to the center */
        ALIGNV_BOTTOM, /**< The text will be vertically aligned to the bottom */
    };

    /**
     * @brief HorizontalAlignment : List of every supported horizontal alignment
     */
    enum HorizontalAlignment {
        ALIGNH_LEFT, /**< The text will be horizontally aligned to the left */
        ALIGNH_CENTER, /**< The text will be horizontally aligned to the center */
        ALIGNH_RIGHT, /**< The text will be horizontally aligned to the right */
    };

    /**
     * @brief Constructor for the Text class
     * @param[in] position : Position of the text on the window
     * @param[in] content : Content of the text
     * @param[in] textColor : Color of the text
     * @param[in] verticalAlignment : Vertical alignment of the text (Defaults to a bottom alignment)
     * @param[in] horizontalAlignment : Horizontal alignment of the text (Defaults to a left alignment)
     * @param[in] textFont : Font of the text (Defaults to the Glut 8x13 Bitmap font)
     * @fn Text(const Vec2D &position, const std::string &content,
         const RGBAcolor &textColor, const VerticalAlignment &verticalAlignment = ALIGNV_BOTTOM,
         const HorizontalAlignment &horizontalAlignment = ALIGNH_LEFT,
         const GlutFont::GlutFonts &textFont = GlutFont::GlutFonts::BITMAP_8_BY_13);
     */
    Text(const Vec2D &position, const std::string &content,
         const RGBAcolor &textColor, const VerticalAlignment &verticalAlignment = ALIGNV_BOTTOM,
         const HorizontalAlignment &horizontalAlignment = ALIGNH_LEFT,
         const GlutFont::GlutFonts &textFont = GlutFont::GlutFonts::BITMAP_8_BY_13);

    virtual std::unique_ptr<IDrawable> clone() const override;

    virtual void getValues(const int &id, std::vector<float> &values) override;
    virtual void setValues(const int &id, const std::vector<float> &values) override;

    /**
     * @brief Computes the width of this text
     * @return The text width
     * @fn int getWidth() const;
     */
    int getWidth() const;

    /**
     * @brief Computes the height of this text
     * @return The text height
     * @fn int getHeight() const;
     */
    int getHeight() const;

protected:
    virtual void draw(MinGL &window) override;

private:
    /**
     * @brief m_position : Position of the text on the window
     */
    Vec2D m_position;

    /**
     * @brief m_content : Content of the text
     */
    std::string m_content;

    /**
     * @brief m_textColor : Color of the text
     */
    RGBAcolor m_textColor;

    /**
     * @brief m_textFont : Font of the text
     */
    GlutFont m_textFont;

    /**
     * @brief m_verticalAlignment : The vertical alignment of the text
     */
    VerticalAlignment m_verticalAlignment;

    /**
     * @brief m_horizontalAlignment : The horizontal alignment of the text
     */
    HorizontalAlignment m_horizontalAlignment;
};

} // namespace nsGui

#endif // GUITEXT_H
