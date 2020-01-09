/*!
 * \file gui_star_background.h
 * \brief A nice star background with blink effects
 * \author SOLLIER Alexandre
 * \version 1.0
 * \date 06 janvier 2020
 */

#ifndef GUI_STAR_BACKGROUND_H
#define GUI_STAR_BACKGROUND_H

#include "../graph/iminglinjectable.h"

#include <chrono>

class GuiStarBackground : public IminGlInjectable
{
public:
    /**
     * @brief Constructor for the GuiStarBackground class
     * @param[in] starCount_ : Number of stars for this instance
     * @param[in] size_ : Background size
     * @param[in] unlitColor_ : Color of an unlit star
     * @param[in] litColor_ : Color of a lit star
     * @param[in] litProbability_ : Probability for a star to change its lit state
     * @fn GuiStarBackground(const unsigned &starCount_, const Vec2D &size_,
                      const RGBcolor &unlitColor_ = RGBcolor(128, 128, 128), const RGBcolor &litColor_ = RGBcolor(192, 192, 192),
                      const float &litProbability_ = 0.05);
     */
    GuiStarBackground(const unsigned &starCount_, const Vec2D &size_,
                      const RGBAcolor &unlitColor_ = RGBAcolor(128, 128, 128), const RGBAcolor &litColor_ = RGBAcolor(192, 192, 192),
                      const float &litProbability_ = 0.05);

    /**
     * @brief Clones the object
     * @fn virtual std::unique_ptr<IDrawable> clone() const override;
     */
    virtual std::unique_ptr<IDrawable> clone() const override;

    /**
     * @brief Updates the element
     * @param[in] delta: Time that the previous frame took to render
     * @fn void Update(std::chrono::milliseconds delta);
     */
    void Update(float delta);

protected:
    /**
     * @brief Renders the element to the provided Window
     * @param[in] Window : Window to render to
     * @fn virtual MinGL & _Edit (MinGL & Window) const;
     */
    virtual void Draw() const override;

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

#endif // GUI_STAR_BACKGROUND_H
