#include "line.h"

#include <cmath>
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;

void Line::Draw() const
{
    // Pour éviter de faire moultes recherches
    /*Vec2D pMin (remarkablePt.find("posMin")->second);
    Vec2D pMax (remarkablePt.find("posMax")->second);
    if (pMin.abs != pMax.abs)
    {
        pair<float, float> equaPminPmax = computeab(pMin, pMax);
        for (unsigned x = pMin.abs; x <= pMax.abs; ++x)
        {
            Window.setPixel(Vec2D(x, (unsigned)ceil(equaPminPmax.first * (float)x + equaPminPmax.second)), borderColor);
        }
    }
    else
    {
        for (unsigned y = pMin.ord; y <= pMax.ord; ++y)
            Window.setPixel(Vec2D(pMin.abs, y), borderColor);
    }*/
}

Line::Line(const Vec2D & pos1, const Vec2D & pos2, const RGBcolor &fillCol)
{
    Vec2D tmp = Vec2D::min (pos1, pos2);

    remarkablePt ["posMin"] = tmp;
    remarkablePt ["posMax"] = ((tmp == pos1) ? pos2 : pos1);

    inColor = borderColor = fillCol;
    name = "line";
}

Line::Line(const BaseFig & b)
{
    if (b.remarkablePt.size() != 2) throw MyException (kNoLine);

    remarkablePt = b.remarkablePt;
    borderColor = b.borderColor;
    inColor = b.inColor;
    name = "triangle";
}

std::unique_ptr<Drawable> Line::clone() const
{
    return std::unique_ptr<Line>(new Line(*this));
}
