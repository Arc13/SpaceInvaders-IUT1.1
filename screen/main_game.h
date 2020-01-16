#ifndef SCREENGAME_H
#define SCREENGAME_H

#include "iscreen.h"

#include <iostream>

#include "../figs/rectangle.h"
#include "../gridmanager/manage_type.h"
#include "../gui/button.h"
#include "../transition/transition_engine.h"

namespace nsScreen {

class MainGame : public IScreen
{
public:
    MainGame();

    virtual void processEvent(const nsEvent::Event_t &event) override;
    virtual void update(const std::chrono::microseconds &delta) override;
    virtual void draw(MinGL &window) override;
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Rectangle m_ennemi;
    std::chrono::microseconds m_deplacementEnnemi;
    std::chrono::microseconds m_tir;
    std::chrono::microseconds m_missile;
    std::chrono::milliseconds m_frtir;
    std::chrono::milliseconds m_frennemi;
    std::chrono::milliseconds m_frmissile;

    nsGame::CVString m_space;
    nsGame::CAObject m_objects;

    unsigned m_Vict;
};

} // namespace nsScreen

#endif // SCREENGAME_H
