/**
 * @file idrawable.h
 * @brief An interface for drawable objects
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 08 janvier 2020
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>

class MinGL;

/**
 * @class IDrawable
 * @brief Interface pour un objet affichable
 */
class IDrawable
{
public:
    /**
     * @brief Destructeur pour la classe IDrawable
     * @fn virtual ~IDrawable() {}
     */
    virtual ~IDrawable() {}

    /**
     * @brief Fonction pour cloner une instance
     * @return Un pointeur unique vers l'objet cloné
     * @fn virtual std::unique_ptr<IDrawable> clone() const;
     */
    virtual std::unique_ptr<IDrawable> clone() const = 0;

    /**
     * @brief Fonction pour afficher l'objet
     * @param[in] window : La fenêtre d'affichage
     * @fn virtual void draw(MinGL &window);
     */
    virtual void draw(MinGL &window) = 0;
};

#endif // DRAWABLE_H
