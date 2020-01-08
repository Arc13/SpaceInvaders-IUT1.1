/*!
 * \file text.h
 * \brief Set of data representing a text that can be displayed
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 28 décembre 2019
 */

#ifndef TEXT_H
#define TEXT_H

#include "../tools/glut_font.h"
#include "../graph/vec2d.h"
#include "rgbcolor.h"

#include <string>

struct Text
{
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
    RGBcolor textColor;

    /**
     * @brief textFont : Font of the text
     */
    GlutFont textFont;

    /**
     * @brief Constructor for the Text class
     * @param[in] position_ : Position of the text on the window
     * @param[in] content_ : Content of the text
     * @param[in] textColor_ : Color of the text
     * @param[in] textFont_ : Font of the text
     * @fn Text(const Vec2D &position_, const std::string &content_, const RGBcolor &textColor_, const GlutFont &textFont_);
     */
    Text(const Vec2D &position_, const std::string &content_, const RGBcolor &textColor_, const GlutFont &textFont_)
        : position(position_)
        , content(content_)
        , textColor(textColor_)
        , textFont(textFont_)
    {}
};

#endif // TEXT_H
