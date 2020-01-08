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
                      const RGBcolor &unlitColor_ = RGBcolor(128, 128, 128), const RGBcolor &litColor_ = RGBcolor(192, 192, 192),
                      const float &litProbability_ = 0.05);

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

    /**
     * @brief Updates the element
     * @param[in] delta: Time that the previous frame took to render
     * @fn void Update(std::chrono::milliseconds delta);
     */
    void Update(std::chrono::milliseconds delta);

protected:
    /**
     * @brief Renders the element to the provided Window
     * @param[in] Window : Window to render to
     * @fn virtual MinGL & _Edit (MinGL & Window) const;
     */
    virtual void Draw () const;

private:
    typedef struct {
        Vec2D pos;
        bool isLit;
    } Star_t;

    std::vector<Star_t> m_stars;

    const RGBcolor m_unlitColor;
    const RGBcolor m_litColor;

    const float m_litProbability;
};

#endif // GUI_STAR_BACKGROUND_H
