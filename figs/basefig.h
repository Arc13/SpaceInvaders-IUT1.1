#ifndef BASEFIG_H
#define BASEFIG_H

#include <map>
#include <memory>

#include "../graph/vec2d.h"
#include "../graph/rgbcolor.h"
#include "../graph/iminglinjectable.h"

class BaseFig : public IminGlInjectable
{
protected:
    virtual void Draw () const override {}
    BaseFig (const std::map<std::string, Vec2D>&, const RGBcolor &, const RGBcolor &);

public:
    BaseFig();
    ~BaseFig() {}

    // Operateur de décalage +
    BaseFig operator + (const Vec2D & pos_) const;
    friend BaseFig operator + (const Vec2D &, const BaseFig &); // Pour la commutativité

    // Operateur de réduction *
    BaseFig operator * (const float & f) const;
    friend BaseFig operator * (const float & f, const BaseFig &); // Pour la commutativité

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

    // Données membres
    // Doivent être public :/ sinon ça pose des soucis dans les conversions
    std::map<std::string, Vec2D> remarkablePt;
    RGBcolor borderColor, inColor;
    std::string name; // ajouter pour l'introspection
    std::string getName() const;
};

#endif // BASEFIG_H
