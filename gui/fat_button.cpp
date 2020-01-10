#include "fat_button.h"

FatButton::FatButton(const Vec2D &position, const Vec2D &size)
    : m_firstColor(255, 0, 0)
    , m_secondColor(0, 255, 0)
    , m_position(position)
    , m_size(size)
{

}

void FatButton::update(float delta)
{

}

std::unique_ptr<IDrawable> FatButton::clone() const
{
    return std::unique_ptr<FatButton>(new FatButton(*this));
}

void FatButton::getValues(const int &id, std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FIRST_RGB:
            values[0] = m_firstColor.Red;
            values[1] = m_firstColor.Green;
            values[2] = m_firstColor.Blue;

            break;
        case TRANSITION_SECOND_RGB:
            values[0] = m_secondColor.Red;
            values[1] = m_secondColor.Green;
            values[2] = m_secondColor.Blue;

            break;
        case TRANSITION_POSITION:
            values[0] = m_position.x;
            values[1] = m_position.y;

            break;
    }
}

void FatButton::setValues(const int &id, const std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FIRST_RGB:
            m_firstColor.Red    = values[0];
            m_firstColor.Green  = values[1];
            m_firstColor.Blue   = values[2];

            break;
        case TRANSITION_SECOND_RGB:
            m_secondColor.Red    = values[0];
            m_secondColor.Green  = values[1];
            m_secondColor.Blue   = values[2];

            break;

        case TRANSITION_POSITION:
            m_position.x    = values[0];
            m_position.y    = values[1];

            break;
    }
}

void FatButton::draw()
{
    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);

    glColor4ub(m_firstColor.Red, m_firstColor.Green, m_firstColor.Blue, m_firstColor.Alpha);
    glVertex2i(m_position.x, m_position.y);
    glVertex2i(m_position.x + m_size.x, m_position.y);

    glColor4ub(m_secondColor.Red, m_secondColor.Green, m_secondColor.Blue, m_secondColor.Alpha);
    glVertex2i(m_position.x + m_size.x, m_position.y + m_size.y);
    glVertex2i(m_position.x, m_position.y + m_size.y);

    glEnd();

    glShadeModel(GL_FLAT);
}
