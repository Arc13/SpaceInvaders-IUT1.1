/**
 * @file text.h
 * @brief Text that can be displayed to a MinGL Window
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 28 décembre 2019
 */

#ifndef GUITEXT_H
#define GUITEXT_H

#include "../tools/glut_font.h"
#include "../graph/iminglinjectable.h"

/**
 * @namespace nsGui
 * @brief Namespace for complex GUI elements
 */
namespace nsGui {

/**
 * @class Text
 * @brief Manages the drawing of a text
 */
class Text : public IminGlInjectable
{
public:
    /**
     * @brief Constructor for the Text class
     * @param[in] position_ : Position of the text on the window
     * @param[in] content_ : Content of the text
     * @param[in] textColor_ : Color of the text
     * @param[in] textFont_ : Font of the text (Defaults to GlutFonts::BITMAP_8_BY_13)
     * @fn Text(const Vec2D &position_, const std::string &content_,
            const RGBcolor &textColor_, const GlutFont &textFont_ = GlutFont(GlutFont::GlutFonts::BITMAP_8_BY_13));
     */
    Text(const Vec2D &position_, const std::string &content_,
            const RGBAcolor &textColor_, const GlutFont::GlutFonts &textFont_ = GlutFont::GlutFonts::BITMAP_8_BY_13);

    virtual std::unique_ptr<IDrawable> clone() const override;

protected:
    virtual void draw() override;

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
};

} // namespace nsGui

#endif // GUITEXT_H
