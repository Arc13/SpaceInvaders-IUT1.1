#include <cmath>

#include "../tools/CstCodErr.h"
#include "circle.h"

using namespace std;
using namespace nsUtil;

void Circle::Draw() const
{
    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int triangleAmount = 20; // Nombre de triangles a dessiner
    const RGBAcolor inColor = getInColor();

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(pos.abs, pos.ord); // Centre du cercle
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha); // Couleur du cercle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(pos.abs + (radius * cos(i * twicePi / triangleAmount)),
                   pos.ord + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
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
