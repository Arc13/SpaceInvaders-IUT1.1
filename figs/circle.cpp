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

Circle::Circle(const Vec2D &pos_, const unsigned &rad, const RGBcolor &borderCol, const RGBcolor &inCol)
{
    remarkablePt["ptCent"] = pos_;
    remarkablePt["radius"] = Vec2D(0, rad);

    borderColor = borderCol;
    inColor = inCol;
    name = "circle";
}

Circle::Circle(const BaseFig & b)
{
    if (b.remarkablePt.size() != 2) throw MyException(kNoTriangle);

    remarkablePt = b.remarkablePt;
    borderColor = b.borderColor;
    inColor = b.inColor;
    name = "circle";
}

Circle Circle::operator +(const Vec2D &pos_) const
{
    Circle tmp(*this);
    tmp.remarkablePt.find("ptCent")->second = tmp.remarkablePt.find("ptCent")->second + pos_;

    return tmp;
}

std::unique_ptr<Drawable> Circle::clone() const
{
    return std::unique_ptr<Circle>(new Circle(*this));
}
