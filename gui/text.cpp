/*!
 * \file gui_text.cpp
 * \brief Text that can be displayed to a MinGL Window
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 28 décembre 2019
 */

#include "text.h"

#define TEXT nsGui::Text

TEXT::Text(const Vec2D &position, const std::string &content,
           const RGBAcolor &textColor, const VerticalAlignment &verticalAlignment,
           const HorizontalAlignment &horizontalAlignment,
           const GlutFont::GlutFonts &textFont)
    : m_position(position)
    , m_content(content)
    , m_textColor(textColor)
    , m_textFont(textFont)
    , m_verticalAlignment(verticalAlignment)
    , m_horizontalAlignment(horizontalAlignment)
{} // Text()

std::unique_ptr<IDrawable> TEXT::clone() const
{
    return std::unique_ptr<Text>(new Text(*this));
} // clone()

void TEXT::getValues(const int &id, std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_COLOR_RGB:
            values[0] = m_textColor.Red;
            values[1] = m_textColor.Green;
            values[2] = m_textColor.Blue;

            break;
        case TRANSITION_COLOR_ALPHA:
            values[0] = m_textColor.Alpha;

            break;
        case TRANSITION_POSITION:
            values[0] = m_position.x;
            values[1] = m_position.y;

            break;
    }
} // getValues()

void TEXT::setValues(const int &id, const std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_COLOR_RGB:
            m_textColor.Red    = values[0];
            m_textColor.Green  = values[1];
            m_textColor.Blue   = values[2];

            break;
        case TRANSITION_COLOR_ALPHA:
            m_textColor.Alpha = values[0];

            break;
        case TRANSITION_POSITION:
            m_position.x = values[0];
            m_position.y = values[1];

            break;
    }
} // setValues()

int TEXT::getWidth() const
{
    return glutBitmapLength(m_textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(m_content.c_str()));
} // getWidth()

int nsGui::Text::getHeight() const
{
    return glutBitmapHeight(m_textFont.convertForGlut());
} // getHeight()

void TEXT::draw(MinGL &window)
{
    // Draw the text with the right color using Glut
    glColor4ub(m_textColor.Red, m_textColor.Green, m_textColor.Blue, m_textColor.Alpha);

    // Set the text position according to its alignment
    int posX = m_position.x;
    switch (m_horizontalAlignment)
    {
        case TEXT::ALIGNH_RIGHT:
            posX -= getWidth();

            break;
        case TEXT::ALIGNH_CENTER:
            posX -= getWidth() / 2;

            break;
        default:
            break;
    }

    int posY = m_position.y;
    switch (m_verticalAlignment)
    {
        case TEXT::ALIGNV_TOP:
            posY += getHeight();

            break;
        case TEXT::ALIGNV_CENTER:
            posY += getHeight() / 2;

            break;
        default:
            break;
    }

    glRasterPos2i(posX, posY);

    glutBitmapString(m_textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(m_content.c_str()));
} // draw()

#undef TEXT
