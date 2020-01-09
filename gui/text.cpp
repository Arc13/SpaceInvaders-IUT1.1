/*!
 * \file gui_text.cpp
 * \brief Text that can be displayed to a MinGL Window
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 28 décembre 2019
 */

#include "text.h"

#define TEXT nsGui::Text

TEXT::Text(const Vec2D &position_, const std::string &content_,
                 const RGBAcolor &textColor_, const GlutFont::GlutFonts &textFont_)
    : m_position(position_)
    , m_content(content_)
    , m_textColor(textColor_)
    , m_textFont(textFont_)
{}

std::unique_ptr<IDrawable> TEXT::clone() const
{
    return std::unique_ptr<Text>(new Text(*this));
}

void TEXT::draw()
{
    // Draw the text with the right color using Glut
    glColor4ub(m_textColor.Red, m_textColor.Green, m_textColor.Blue, m_textColor.Alpha);
    glRasterPos2i(m_position.x, m_position.y);

    glutBitmapString(m_textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(m_content.c_str()));
}

#undef TEXT
