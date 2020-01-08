#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>

class Drawable
{
public:
    virtual ~Drawable() {}
    virtual std::unique_ptr<Drawable> clone() const = 0;
    virtual void Draw() const = 0;
};

#endif // DRAWABLE_H
