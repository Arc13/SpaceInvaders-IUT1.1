#include <iostream>

#include "basefig.h"

using namespace std;

BaseFig::BaseFig()
{}

BaseFig::BaseFig(const std::map<string, Vec2D> & pt, const RGBcolor & bdCol, const RGBcolor & inCol)
    : remarkablePt (pt)
    , borderColor (bdCol)
    , inColor (inCol)
    , name (string ())
{}

BaseFig BaseFig::operator +(const Vec2D &pos_) const
{
    map <string, Vec2D> tmp = this->remarkablePt;
    for (auto & pt : tmp)
        pt.second = pt.second + pos_;

    return BaseFig (tmp, borderColor, inColor);
}

BaseFig BaseFig::operator *(const float &f) const
{
    map <string, Vec2D> tmp = this->remarkablePt;
    for (auto & pt : tmp)
        pt.second = pt.second * f;

    return BaseFig (tmp, borderColor, inColor);
}

std::unique_ptr<Drawable> BaseFig::clone() const
{
    return std::unique_ptr<BaseFig>(new BaseFig(*this));
}

string BaseFig::getName() const
{
    return name;
}

BaseFig operator *(const float &f, const BaseFig & B)
{
    return B * f;
}

BaseFig operator +(const Vec2D & pos_, const BaseFig & B)
{
    return B + pos_;
}
