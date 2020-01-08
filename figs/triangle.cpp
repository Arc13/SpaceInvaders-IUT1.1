#include "triangle.h"

#include <vector>
#include <algorithm>

#include "../tools/CstCodErr.h"
#include "../tools/tools.h"
#include "line.h"

using namespace std;
using namespace nsUtil;

void Triangle::Draw() const
{
    // Pour éviter de faire moultes recherches
    /*Vec2D pMin(remarkablePt.find("posMin")->second);
    Vec2D pInt(remarkablePt.find("posInt")->second);
    Vec2D pMax(remarkablePt.find("posMax")->second);
    pair<float, float> equaPminPmax = computeab(pMin, pMax);
    pair<float, float> equaPminPint = computeab(pMin, pInt);
    pair<float, float> equaPintPmax = computeab(pInt, pMax);

    // L'intérieur
    // Si pInt est au dessus de la droite pMin -- pMax
    if (pInt.ord > equaPminPmax.first * pInt.abs + equaPminPmax.second)
    {
        // On va de pMin a pInt
        for (unsigned x = pMin.abs + 1; x < pInt.abs; ++x)
            for (unsigned y = equaPminPmax.first * x + equaPminPmax.second + 1;
                 y < equaPminPint.first * x + equaPminPint.second; ++y)
                Window.setPixel(Vec2D(x, y), inColor);

        // On va de pInt a pMax
        for (unsigned x = pInt.abs; x < pMax.abs; ++x)
            for (unsigned y = equaPminPmax.first * x + equaPminPmax.second + 1;
                 y < equaPintPmax.first * x + equaPintPmax.second; ++y)
                Window.setPixel(Vec2D(x, y), inColor);
    }
    else
    {
        // On va de pMin a pInt
        for (unsigned x = pMin.abs + 1; x < pInt.abs; ++x)
            for (unsigned y = equaPminPint.first * x + equaPminPint.second +1;
                 y < equaPminPmax.first * x + equaPminPmax.second; ++y)
                Window.setPixel(Vec2D(x, y), inColor);

        // On va de pInt a pMax
        for (unsigned x = pInt.abs + (pInt.abs == pMin.abs ? 1 : 0); x < pMax.abs; ++x)
            for (unsigned y = equaPintPmax.first * x + equaPintPmax.second + 1;
                 y < equaPminPmax.first * x + equaPminPmax.second; ++y)
                Window.setPixel(Vec2D(x, y), inColor);
    }
    // La bordure
    Window << Line(pMin, pMax, borderColor);
    Window << Line(pMin, pInt, borderColor);
    Window << Line(pInt, pMax, borderColor);*/
}

Triangle::Triangle(const Vec2D &pos1, const Vec2D &pos2, const Vec2D &pos3, const RGBcolor &borderCol_, const RGBcolor &fillCol_)
{
    vector<Vec2D> Vpos {pos1, pos2, pos3};
    sort(Vpos.begin(), Vpos.end (), Vec2D::minf);

    remarkablePt["posMin"] = Vpos[0];
    remarkablePt["posInt"] = Vpos[1];
    remarkablePt["posMax"] = Vpos[2];

    borderColor = borderCol_;
    inColor = fillCol_;
    name = "triangle";
}

Triangle::Triangle(const BaseFig & b)
{
    if (b.remarkablePt.size() != 3) throw MyException(kNoTriangle);

    remarkablePt = b.remarkablePt;
    borderColor = b.borderColor;
    inColor = b.inColor;
    name = "triangle";
}

std::unique_ptr<Drawable> Triangle::clone() const
{
    return std::unique_ptr<Triangle>(new Triangle(*this));
}
