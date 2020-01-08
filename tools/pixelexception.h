#ifndef PIXELEXCEPTION_H
#define PIXELEXCEPTION_H

#include <exception>
#include "../graph/vec2d.h"
#include "../graph/rgbcolor.h"

class PixelException : public std::exception
{
public:
    PixelException(const Vec2D &pixelPosition, const RGBcolor &color, const std::string &problem);
    const char* what() const noexcept;

private:
    Vec2D pixelPosition;
    RGBcolor pixelColor;
    std::string problem;
};

#endif // PIXELEXCEPTION_H
