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

Line::Line(const Vec2D & pos1_, const Vec2D & pos2_, const RGBAcolor &fillCol_)
    : BaseFig(fillCol_, fillCol_, "line")
    , pos1(pos1_)
    , pos2(pos2_)
{

}

Line::Line(const BaseFig & b)
    : BaseFig(b.getInColor(), b.getBorderColor(), b.getName())
{

}

std::unique_ptr<Drawable> Line::clone() const
{
    return std::unique_ptr<Line>(new Line(*this));
}
