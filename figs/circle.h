#ifndef CIRCLE_H
#define CIRCLE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Circle : public BaseFig
{
public:
    Circle(const Vec2D & pos_, const unsigned & rad_, const RGBcolor & inCol_, const RGBcolor & borderCol_ = RGBcolor ());
    Circle(const BaseFig &);
    virtual ~Circle() {}

    virtual void Draw() const override;

    // Opérateur de décalage +
    Circle operator + (const Vec2D & pos_) const {
        return Circle(pos + pos_, radius, inColor, borderColor);
    }

    // Opérateur de réduction *
    Circle operator * (const float & f) const {
        return Circle(pos * f, radius, inColor, borderColor);
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

private:
    Vec2D pos;
    unsigned radius;
};

#endif // CIRCLE_H
