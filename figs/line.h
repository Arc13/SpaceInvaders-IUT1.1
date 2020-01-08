#ifndef LINE_H
#define LINE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Line : public BaseFig
{
protected:
    virtual void Draw() const override;

public:
    Line (const Vec2D& pos1_, const Vec2D & pos2_, const RGBcolor & fillCol_ = RGBcolor ());
    Line (const BaseFig &);
    virtual ~Line() {}

    // Opérateur de décalage +
    Line operator + (const Vec2D & pos_) const {
        return Line(pos1 + pos_, pos2 + pos_, getInColor());
    }

    // Opérateur de réduction *
    Line operator * (const float & f) const {
        return Line(pos1 * f, pos2 * f, getInColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

private:
    Vec2D pos1;
    Vec2D pos2;
};

#endif // LINE_H
