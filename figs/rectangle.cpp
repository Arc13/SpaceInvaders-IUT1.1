#include "rectangle.h"

#include "../tools/CstCodErr.h"
#include "triangle.h"
#include "line.h"

using namespace std;
using namespace nsUtil;

void Rectangle::Draw() const
{
    // Pour éviter de faire moultes recherches
    /*Vec2D botLeft(remarkablePt.find("botLeft")->second);
    Vec2D topLeft(remarkablePt.find("topLeft")->second);
    Vec2D botRight(remarkablePt.find("botRight")->second);
    Vec2D topRight(remarkablePt.find("topRight")->second);

    // La bordure
    Window << Line(botLeft, topLeft, borderColor);
    Window << Line(topLeft, topRight, borderColor);
    Window << Line(topRight, botRight, borderColor);
    Window << Line(botRight, botLeft, borderColor);

    // L'intérieur
    for (unsigned x = botLeft.abs + 1; x < topRight.abs; ++x)
        for (unsigned y = botLeft.ord +1; y < topRight.ord; ++y)
            Window.setPixel (Vec2D(x, y), inColor);*/

    glColor4ub(128, 0, 0, 128);
    glRecti(10, 10, 200, 200);
}

Rectangle::Rectangle(const Vec2D &pos1, const Vec2D &pos2, const RGBcolor &borderCol, const RGBcolor &inCol)
{
    remarkablePt["botLeft"]  = Vec2D(min(pos1.abs, pos2.abs), min(pos1.ord, pos2.ord));
    remarkablePt["topLeft"]  = Vec2D(min(pos1.abs, pos2.abs), max(pos1.ord, pos2.ord));
    remarkablePt["botRight"] = Vec2D(max(pos1.abs, pos2.abs), min(pos1.ord, pos2.ord));
    remarkablePt["topRight"] = Vec2D(max(pos1.abs, pos2.abs), max(pos1.ord, pos2.ord));

    borderColor = borderCol;
    inColor = inCol;
    name = "rectangle";
}

Rectangle::Rectangle(const Vec2D &pos_, const unsigned &width, const unsigned &height, const RGBcolor &borderCol, const RGBcolor &inCol)
{
    remarkablePt["botLeft"]  = pos_;
    remarkablePt["topLeft"]  = pos_ + Vec2D(0, height);
    remarkablePt["botRight"] = pos_ + Vec2D(width, 0);
    remarkablePt["topRight"] = pos_ + Vec2D(width, height);

    borderColor = borderCol;
    inColor = inCol;
    name = "rectangle";
}

Rectangle::Rectangle(const BaseFig & b)
{
    if (b.remarkablePt.size() != 4) throw MyException(kNoRectangle);

    remarkablePt = b.remarkablePt;
    borderColor = b.borderColor;
    inColor = b.inColor;
    name = "rectangle";
}

std::unique_ptr<Drawable> Rectangle::clone() const
{
    return std::unique_ptr<Rectangle>(new Rectangle(*this));
}
