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
    // On règle la couleur du triangle
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On dessine le triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(pos1.abs, pos1.ord);
    glVertex2i(pos2.abs, pos2.ord);
    glVertex2i(pos3.abs, pos3.ord);
    glEnd();
}

Triangle::Triangle(const Vec2D &pos1_, const Vec2D &pos2_, const Vec2D &pos3_, const RGBAcolor &fillCol_, const RGBAcolor &borderCol_)
    : BaseFig(fillCol_, borderCol_, "triangle")
    , pos1(pos1_)
    , pos2(pos2_)
    , pos3(pos3_)
{

}

Triangle::Triangle(const BaseFig & b)
    : BaseFig(b.getInColor(), b.getBorderColor(), b.getName())
{

}

std::unique_ptr<Drawable> Triangle::clone() const
{
    return std::unique_ptr<Triangle>(new Triangle(*this));
}
