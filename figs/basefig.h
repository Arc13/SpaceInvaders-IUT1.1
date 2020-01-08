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
    BaseFig (const RGBcolor &, const RGBcolor &, const std::string &);

public:
    BaseFig();
     ~BaseFig() {}

    virtual void Draw () const override {}

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;

    const RGBcolor getInColor() const;
    const RGBcolor getBorderColor() const;

    // Données membres
    // Doivent être public :/ sinon ça pose des soucis dans les conversions
    RGBcolor inColor, borderColor;
    std::string name; // ajouter pour l'introspection
    std::string getName() const;
};

#endif // BASEFIG_H
