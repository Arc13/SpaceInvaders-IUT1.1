/*!
 * \file gui_text.cpp
 * \brief Text that can be displayed to a MinGL Window
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 28 décembre 2019
 */

#include "gui_text.h"

GuiText::GuiText(const Vec2D &position_, const std::string &content_,
                 const RGBcolor &textColor_, const GlutFont &textFont_)
    : Text(position_, content_, textColor_, textFont_)
{}

std::unique_ptr<Drawable> GuiText::clone() const
{
    return std::unique_ptr<GuiText>(new GuiText(*this));
}

void GuiText::Draw() const
{
    glColor3ub(textColor.Red, textColor.Green, textColor.Blue);
    glRasterPos2i(position.abs, position.ord);

    glutBitmapString(textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(content.c_str()));
}
