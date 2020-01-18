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
 * @brief Gère l'affichage et l'animation d'un fond étoilé
 */
class StarBackground : public IminGlInjectable
{
public:
    /**
     * @brief Constructeur pour la classe StarBackground
     * @param[in] starCount : Nombre d'étoiles pour cette instance
     * @param[in] size : Taille du fond
     * @param[in] unlitColor : Couleur pour une étoile éteinte (Gris par défaut)
     * @param[in] litColor : Couleur pour une étoile allumée (Gris clair par défaut)
     * @param[in] litProbability : Probabilité pour une étoile de s'allumer/s'éteindre (5% par défaut)
     * @fn StarBackground(const unsigned &starCount, const Vec2D &size,
                      const RGBAcolor &unlitColor = RGBAcolor(128, 128, 128), const RGBAcolor &litColor = RGBAcolor(192, 192, 192),
                      const float &litProbability = 0.05);
     */
    StarBackground(const unsigned &starCount, const Vec2D &size,
                      const RGBAcolor &unlitColor = RGBAcolor(128, 128, 128), const RGBAcolor &litColor = RGBAcolor(192, 192, 192),
                      const float &litProbability = 0.05);

    /**
     * @brief Met à jour l'élément
     * @param[in] delta: Temps que la dernière image a mis pour faire son rendu
     * @fn void update(float delta);
     */
    void update(float delta);

    virtual std::unique_ptr<IDrawable> clone() const override;
    virtual void draw(MinGL &window) override;

private:
    /**
     * @brief Une structure représentant une étoile
     */
    typedef struct {
        Vec2D pos; /**< Position de l'étoile */
        bool isLit; /**< Etat d'allumage de l'étoile */
    } Star_t;

    /**
     * @brief m_stars : Vecteur d'étoiles de cette instance
     */
    std::vector<Star_t> m_stars;

    /**
     * @brief m_unlitColor : Couleur d'une étoile éteinte
     */
    const RGBAcolor m_unlitColor;

    /**
     * @brief m_litColor : Couleur d'une étoile allumée
     */
    const RGBAcolor m_litColor;

    /**
     * @brief m_litProbability : Probabilité pour une étoile de s'allumer/s'éteindre
     */
    const float m_litProbability;
};

} // namespace nsGui

#endif // GUI_STAR_BACKGROUND_H
