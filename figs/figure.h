#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <memory>
#include <type_traits>

#include "../graph/iminglinjectable.h"
#include "basefig.h"
#include "circle.h"

class Figure : public BaseFig
{
protected:
    virtual void Draw() const;
    std::vector<std::shared_ptr<BaseFig>> vFig;

public:
    template <typename T, typename = typename std::enable_if<std::is_base_of<BaseFig, T>::value>::type>
    void Add (const T & Val)
    {
        std::shared_ptr<T> ptr (new T (Val));
        vFig.push_back(ptr);

    }

    // Opérateur de décalage +
    /*virtual*/ Figure operator + (const Vec2D & pos_) const;

    friend Figure operator + (const Vec2D & p, const Figure & f)
    {
        return f + p;
    } // Pour la commutativité

    // Opérateur de réduction *
    /*virtual*/ Figure operator * (const float & f) const;

    friend Figure operator * (const float & f, const Figure & fig)
    {
        return fig * f;
    } // Pour la commutativité

    // Fonction de clonage
    virtual std::unique_ptr<Drawable> clone() const override;
};

#endif // FIGURE_H
