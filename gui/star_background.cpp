/**
 * @file star_background.cpp
 * @brief Un joli ciel étoilé avec des effets de clignotement
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 06 janvier 2020
 */

#include "star_background.h"

#include "../macros.h"

#define STARBACKGROUND nsGui::StarBackground

STARBACKGROUND::StarBackground(const unsigned &starCount, const Vec2D &size,
                               const RGBAcolor &unlitColor, const RGBAcolor &litColor, const float &litProbability)
    : m_unlitColor(unlitColor)
    , m_litColor(litColor)
    , m_litProbability(litProbability)
{
    // Initialise the RNG seed
    srand(time(NULL));

    for (unsigned i = 0; i < starCount; ++i) {
        // Put a new star at random coordinates, unlit by default, in the star vector
        m_stars.push_back({Vec2D(rand() % size.x, rand() % size.y), false});
    }
} // StarBackground()

std::unique_ptr<IDrawable> STARBACKGROUND::clone() const
{
    return std::unique_ptr<StarBackground>(new StarBackground(*this));
}

void STARBACKGROUND::draw(MinGL &window)
{
    UNUSED(window);

    // Draw the stars as points
    glBegin(GL_POINTS);

    for (const Star_t &star: m_stars) {
        const RGBAcolor currentColor = star.isLit ? m_litColor : m_unlitColor;

        glColor3ub(currentColor.Red, currentColor.Green, currentColor.Blue);
        glVertex2i(star.pos.x, star.pos.y);
    }

    glEnd();
} // draw()

void STARBACKGROUND::update(float delta)
{
    UNUSED(delta);

    // For each star, generate a random number: 0 < n < 1
    // The star lit state will be inverted if 0 < n < m_litProbability
    for (Star_t &star: m_stars) {
        const double randNumber = rand() / (double)RAND_MAX;
        if (randNumber <= m_litProbability) {
            star.isLit = !star.isLit;
        }
    }
} // update()

#undef STARBACKGROUND
