#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Rectangle : public BaseFig
{
public:
    Rectangle(const Vec2D & pos1_, const Vec2D & pos2_, const RGBcolor & inCol_, const RGBcolor & borderCol_ = RGBcolor ());
    Rectangle(const Vec2D & Vec2D_, const unsigned & width_, const unsigned & height_, const RGBcolor & inCol_, const RGBcolor & borderCol_ = RGBcolor ());
    Rectangle (const BaseFig &);
    virtual ~Rectangle() {}

    virtual void Draw() const override;

    // Opérateur de décalage +
    Rectangle operator + (const Vec2D & pos_) const {
        return Rectangle(pos1 + pos_, pos2 + pos_, inColor, borderColor);
    }

    // Opérateur de réduction *
    Rectangle operator * (const float & f) const {
        return Rectangle(pos1 * f, pos2 * f, inColor, borderColor);
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

private:
    Vec2D pos1;
    Vec2D pos2;
};

#endif // RECTANGLE_H
