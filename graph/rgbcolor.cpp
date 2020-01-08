#include "rgbcolor.h"

std::ostream &RGBcolor::_Edit(std::ostream &os) const
{
    os << "R: " << int(Red) << ", G: " << int(Green) << ", B: " << int(Blue);
    return os;
}
