#include <iostream>

#include "basefig.h"

using namespace std;

BaseFig::BaseFig()
{}

BaseFig::BaseFig(const RGBcolor & inCol_, const RGBcolor & bdCol_, const std::string &name_)
    : inColor (inCol_)
    , borderColor (bdCol_)
    , name (name_)
{}

std::unique_ptr<Drawable> BaseFig::clone() const
{
    return std::unique_ptr<BaseFig>(new BaseFig(*this));
}

const RGBcolor BaseFig::getBorderColor() const
{
    return borderColor;
}

const RGBcolor BaseFig::getInColor() const
{
    return inColor;
}

string BaseFig::getName() const
{
    return name;
}
