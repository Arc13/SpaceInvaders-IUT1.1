#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Rectangle : public BaseFig
{
protected:
    virtual void Draw() const override;

public:
    Rectangle(const Vec2D & pos1, const Vec2D & pos2, const RGBcolor & borderCol, const RGBcolor & inCol = RGBcolor ());
    Rectangle(const Vec2D & Vec2D, const unsigned & width, const unsigned & height, const RGBcolor & borderCol, const RGBcolor & inCol = RGBcolor ());
    Rectangle (const BaseFig &);
    ~Rectangle() {}

    // Opérateur de décalage +
    Rectangle operator + (const Vec2D & pos_) const {
        return BaseFig::operator +(pos_);
    }

    friend Rectangle operator + (const Vec2D & p, const Rectangle & t) {
        return t + p;
    }

    // Opérateur de réduction *
    Rectangle operator * (const float & f) const {
        return BaseFig::operator *(f);
    }

    friend Rectangle operator * (const float & f, const Rectangle & t) {
        return t * f;
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;
};

#endif // RECTANGLE_H
