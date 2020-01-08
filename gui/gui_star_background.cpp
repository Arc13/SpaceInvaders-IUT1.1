/*!
 * \file gui_star_background.h
 * \brief A nice star background with blink effects
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 06 janvier 2020
 */

#include "gui_star_background.h"

GuiStarBackground::GuiStarBackground(const unsigned &starCount_, const Vec2D &size_, const RGBcolor &unlitColor_, const RGBcolor &litColor_, const float &litProbability_)
    : m_unlitColor(unlitColor_)
    , m_litColor(litColor_)
    , m_litProbability(litProbability_)
{
    srand(time(NULL));
    for (unsigned i = 0; i < starCount_; ++i) {
        // Put a new star at random coordinates, unlit by default, in the star vector
        m_stars.push_back({Vec2D(rand() % size_.abs, rand() % size_.ord), false});
    }
}

std::unique_ptr<Drawable> GuiStarBackground::clone() const
{
    return std::unique_ptr<GuiStarBackground>(new GuiStarBackground(*this));
}

void GuiStarBackground::Update(std::chrono::milliseconds delta)
{
    for (Star_t &star: m_stars) {
        const double randNumber = rand() / (double)RAND_MAX;
        if (randNumber <= m_litProbability) {
            star.isLit = !star.isLit;
        }
    }
}

void GuiStarBackground::Draw() const
{
    glBegin(GL_POINTS);

    for (const Star_t &star: m_stars) {
        const RGBcolor currentColor = star.isLit ? m_litColor : m_unlitColor;

        glColor3ub(currentColor.Red, currentColor.Green, currentColor.Blue);
        glVertex2i(star.pos.abs, star.pos.ord);
    }

    glEnd();
}
