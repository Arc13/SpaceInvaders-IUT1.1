#ifndef CIRCLE_H
#define CIRCLE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Circle : public BaseFig
{
protected:
    virtual void Draw() const;

public:
    Circle(const Vec2D & pos_, const unsigned & rad, const RGBcolor & borderCol, const RGBcolor & inCol = RGBcolor ());
    Circle(const BaseFig &);
    ~Circle() {}

    // Operateur de décalage +
    /*virtual*/ Circle operator + (const Vec2D & pos_) const;

    friend Circle operator + (const Vec2D & p, const Circle & t)
    {
        return t + p;
    }

    // Operateur de reduction *
    /*virtual*/ Circle operator * (const float & f) const
    {
        return BaseFig::operator *(f);
    }

    friend Circle operator * (const float & f, const Circle & t)
    {
        return t * f;
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;
};

#endif // CIRCLE_H
