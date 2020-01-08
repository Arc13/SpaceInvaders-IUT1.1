#include "rectangle.h"

#include "../tools/CstCodErr.h"
#include "triangle.h"
#include "line.h"

using namespace std;
using namespace nsUtil;

void Rectangle::Draw() const
{
    // On règle la couleur du rectangle
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // Affiche un rectangle via la routine OpenGL
    glRecti(pos1.abs, pos1.ord, pos2.abs, pos2.ord);

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);
        glVertex2i(pos1.abs, pos1.ord);
        glVertex2i(pos1.abs, pos2.ord);
        glVertex2i(pos2.abs, pos2.ord);
        glVertex2i(pos2.abs, pos1.ord);
        glEnd();
    }
}

Rectangle::Rectangle(const Vec2D &pos1_, const Vec2D &pos2_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : BaseFig(inCol_, borderCol_, "rectangle")
    , pos1(pos1_)
    , pos2(pos2_)
{

}

Rectangle::Rectangle(const Vec2D &pos_, const unsigned &width_, const unsigned &height_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : BaseFig(inCol_, borderCol_, "rectangle")
    , pos1(pos_)
    , pos2(Vec2D(pos_.abs + width_, pos_.ord + height_))
{

}

Rectangle::Rectangle(const BaseFig & b)
    : BaseFig(b.getInColor(), b.getBorderColor(), b.getName())
{

}

std::unique_ptr<Drawable> Rectangle::clone() const
{
    return std::unique_ptr<Rectangle>(new Rectangle(*this));
}
