#include "line.h"

#include <cmath>
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;

void Line::Draw() const
{
    // On met la couleur de la ligne
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On règle le volume de la ligne
    glLineWidth(lineWidth);

    // On dessine la ligne
    glBegin(GL_LINES);
    glVertex2i(pos1.abs, pos1.ord);
    glVertex2i(pos2.abs, pos2.ord);
    glEnd();
}

Line::Line(const Vec2D & pos1_, const Vec2D & pos2_, const RGBAcolor &fillCol_, const float &lineWidth_)
    : BaseFig(fillCol_, fillCol_, "line")
    , pos1(pos1_)
    , pos2(pos2_)
    , lineWidth(lineWidth_)
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
