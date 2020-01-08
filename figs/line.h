#ifndef LINE_H
#define LINE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Line : public BaseFig
{
protected:
    virtual void Draw() const;

public:
    Line (const Vec2D& pix1, const Vec2D & pix2, const RGBcolor & fillCol = RGBcolor ());
    Line (const BaseFig &);
    ~Line() {}

    // Opérateur de décalage +
    Line operator + (const Vec2D & pos_) const {
        return BaseFig::operator +(pos_);
    }

    friend Line operator + (const Vec2D & p, const Line & t) {
        return t + p;
    }

    // Opérateur de réduction *
    Line operator * (const float & f) const {
        return BaseFig::operator *(f);
    }

    friend Line operator * (const float & f, const Line & t) {
        return t * f;
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;
};

#endif // LINE_H
