#ifndef SCREENMAINMENU_H
#define SCREENMAINMENU_H

#include "iscreen.h"

#include <iostream>

class ScreenMainMenu : public IScreen
{
public:
    virtual void processEvent(const Event::Event &event) override;
    virtual void update(const float &delta) override;
    virtual void draw(MinGL &window) override;
};

#endif // SCREENMAINMENU_H
