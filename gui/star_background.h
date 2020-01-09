/**
 * @file star_background.h
 * @brief A nice star background with blink effects
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 06 janvier 2020
 */

#ifndef GUI_STAR_BACKGROUND_H
#define GUI_STAR_BACKGROUND_H

#include "../graph/iminglinjectable.h"

#include <chrono>

namespace nsGui {

/**
 * @class StarBackground
 * @brief Manages the drawing and animation of the stars
 */
class StarBackground : public IminGlInjectable
{
public:
    /**
     * @brief Constructor for the StarBackground class
     * @param[in] starCount_ : Number of stars for this instance
     * @param[in] size_ : Background size
     * @param[in] unlitColor_ : Color of an unlit star
     * @param[in] litColor_ : Color of a lit star
     * @param[in] litProbability_ : Probability for a star to change its lit state
     * @fn StarBackground(const unsigned &starCount_, const Vec2D &size_,
                      const RGBcolor &unlitColor_ = RGBcolor(128, 128, 128), const RGBcolor &litColor_ = RGBcolor(192, 192, 192),
                      const float &litProbability_ = 0.05);
     */
    StarBackground(const unsigned &starCount_, const Vec2D &size_,
                      const RGBAcolor &unlitColor_ = RGBAcolor(128, 128, 128), const RGBAcolor &litColor_ = RGBAcolor(192, 192, 192),
                      const float &litProbability_ = 0.05);

    /**
     * @brief Updates the element
     * @param[in] delta: Time that the previous frame took to render
     * @fn void update(float delta);
     */
    void update(float delta);

    virtual std::unique_ptr<IDrawable> clone() const override;

protected:
    virtual void draw() override;

private:
    /**
     * @brief A structure that represents a single star
     */
    typedef struct {
        Vec2D pos; /**< The position of the star */
        bool isLit; /**< Is the star brighter? */
    } Star_t;

    /**
     * @brief m_stars : Holds the star for this instance
     */
    std::vector<Star_t> m_stars;

    /**
     * @brief m_unlitColor : The color for an unlit star
     */
    const RGBAcolor m_unlitColor;

    /**
     * @brief m_litColor : The color for a lit star
     */
    const RGBAcolor m_litColor;

    /**
     * @brief m_litProbability : The probability for a star to lit/unlit itself
     */
    const float m_litProbability;
};

} // namespace nsGui

#endif // GUI_STAR_BACKGROUND_H
