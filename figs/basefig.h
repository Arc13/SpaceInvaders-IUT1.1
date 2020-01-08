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
    const std::string getName() const;

    void setInColor(const RGBcolor &inColor_);
    void setBorderColor(const RGBcolor &borderColor_);

private:
    RGBcolor inColor, borderColor;
    const std::string name; // ajouter pour l'introspection
};

#endif // BASEFIG_H
