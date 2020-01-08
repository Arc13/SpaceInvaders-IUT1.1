#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "basefig.h"

#include "../tools/myexception.h"
#include "../graph/iminglinjectable.h"

class Triangle : public BaseFig
{
protected:
    virtual void Draw() const;
public:
    Triangle(const Vec2D & pos1, const Vec2D &pos2, const Vec2D & pos3, const RGBcolor & borderCol_, const RGBcolor & fillCol_ = RGBcolor ());
    Triangle (const BaseFig &);
    ~Triangle() {}

    // Opérateur de décalage +
    Triangle operator + (const Vec2D & pos_) const {
        return BaseFig::operator +(pos_);
    }

    friend Triangle operator + (const Vec2D & p, const Triangle & t) {
        return t + p;
    }

    // Opérateur de réduction *
    Triangle operator * (const float & f) const {
        return BaseFig::operator *(f);
    }

    friend Triangle operator * (const float & f, const Triangle & t) {
        return t * f;
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;
};

#endif // TRIANGLE_H
