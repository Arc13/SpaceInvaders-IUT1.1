#include <cmath>

#include "../tools/CstCodErr.h"
#include "circle.h"

using namespace std;
using namespace nsUtil;

void Circle::Draw() const
{
    // Pour éviter de faire moultes recherches
    /*Vec2D center(remarkablePt.find("ptCent")->second);
    unsigned radius(remarkablePt.find("radius")->second.ord);

    // La bordure
    double j, inc = asin((double)1 / radius);
    for (j = 0; j < 360; j += inc)
    {
      Window.setPixel(Vec2D (center.abs+cos(j)*radius, center.ord+sin(j)*radius), borderColor);
    }

    // L'intérieur
    for (unsigned i = 0; i < radius - 1; ++i)
    {
        for (unsigned j = 0; j < sqrt(radius*radius - i*i) -1; ++j)
        {
            Window.setPixel(Vec2D(center.abs + j, center.ord + i), inColor);
            Window.setPixel(Vec2D(center.abs - j, center.ord + i), inColor);
            Window.setPixel(Vec2D(center.abs + j, center.ord - i), inColor);
            Window.setPixel(Vec2D(center.abs - j, center.ord - i), inColor);
        }
    }*/
}

Circle::Circle(const Vec2D &pos_, const unsigned &rad_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : BaseFig(inCol_, borderCol_, "circle")
    , pos(pos_)
    , radius(rad_)
{

}

Circle::Circle(const BaseFig & b)
    : BaseFig(b.getInColor(), b.getBorderColor(), b.getName())
{

}

std::unique_ptr<Drawable> Circle::clone() const
{
    return std::unique_ptr<Circle>(new Circle(*this));
}
