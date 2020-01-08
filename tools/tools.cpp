#include "tools.h"

/*
 * Renvoie le coefficient de la droite passant par pt1 et pt2, ET
 * pair<coef_directeur, decalage>
 */
std::pair<float, float> computeab(const Vec2D & pt1, const Vec2D & pt2)
{
    float a = (float ((int)pt2.ord - (int)pt1.ord)) / (float ((int)pt2.abs - (int)pt1.abs));
    float b = pt2.ord - a * pt2.abs;

    return std::make_pair (a,b);
} // computeab()
