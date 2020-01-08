/*!
 * \file gui_text.h
 * \brief Text that can be displayed to a MinGL Window
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 28 décembre 2019
 */

#ifndef GUITEXT_H
#define GUITEXT_H

#include "../tools/glut_font.h"
#include "../graph/iminglinjectable.h"

class GuiText : public IminGlInjectable
{
public:
    /**
     * @brief Constructor for the GuiText class
     * @param[in] position_ : Position of the text on the window
     * @param[in] content_ : Content of the text
     * @param[in] textColor_ : Color of the text
     * @param[in] textFont_ : Font of the text (Defaults to GlutFonts::BITMAP_8_BY_13)
     * @fn GuiText(const Vec2D &position_, const std::string &content_,
            const RGBcolor &textColor_, const GlutFont &textFont_ = GlutFont(GlutFont::GlutFonts::BITMAP_8_BY_13));
     */
    GuiText(const Vec2D &position_, const std::string &content_,
            const RGBAcolor &textColor_, const GlutFont::GlutFonts &textFont_ = GlutFont::GlutFonts::BITMAP_8_BY_13);

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

protected:
    /**
     * @brief Renders the element to the provided Window
     * @param[in] Window : Window to render to
     * @fn virtual MinGL & _Edit (MinGL & Window) const;
     */
    virtual void Draw() const override;

    /**
     * @brief position : Position of the text on the window
     */
    Vec2D position;

    /**
     * @brief content : Content of the text
     */
    std::string content;

    /**
     * @brief textColor : Color of the text
     */
    RGBAcolor textColor;

    /**
     * @brief textFont : Font of the text
     */
    GlutFont textFont;
};

#endif // GUITEXT_H
