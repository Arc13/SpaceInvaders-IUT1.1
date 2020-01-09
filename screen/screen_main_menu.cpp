#include "screen_main_menu.h"

#include <iostream>

#include "gui/gui_text.h"
#include "gui/gui_star_background.h"

#include "figs/line.h"
#include "figs/rectangle.h"
#include "figs/triangle.h"
#include "figs/circle.h"
#include "figs/figure.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"

void ScreenMainMenu::processEvent(const Event::Event &event) {
    // Fonction appelée a chaque évènement
    if (event.eventType == Event::MouseClick) {
        std::cout << "click: " << event.eventData.clickData.x << ", " << event.eventData.clickData.y << std::endl;
    } else if (event.eventType == Event::MouseMove) {
        std::cout << "move: " << event.eventData.moveData.x << ", " << event.eventData.moveData.y << std::endl;
    }
}

void ScreenMainMenu::update(const float &delta) {
    // Fonction appelée a chaque frame, s'occupe exclusivement de la logique
}

void ScreenMainMenu::draw(MinGL &window) {
    // Fonction appelée a chaque frame, s'occupe exclusivement de l'affichage

    // On injecte tout ce qui doit être affiché
    window << GuiText(Vec2D(10, 110), "BITMAP 8x13", KRed);
    window << GuiText(Vec2D(10, 125), "BITMAP 9x15", KRed, GlutFont::BITMAP_9_BY_15);
    window << GuiText(Vec2D(10, 140), "HELVETICA 10", KBlue, GlutFont::BITMAP_HELVETICA_10);
    window << GuiText(Vec2D(10, 155), "HELVETICA 12", KBlue, GlutFont::BITMAP_HELVETICA_12);
    window << GuiText(Vec2D(10, 175), "HELVETICA 18", KBlue, GlutFont::BITMAP_HELVETICA_18);
    window << GuiText(Vec2D(10, 195), "TIMES NEW ROMAN 10", KGreen, GlutFont::BITMAP_TIMES_ROMAN_10);
    window << GuiText(Vec2D(10, 215), "TIMES NEW ROMAN 24", KGreen, GlutFont::BITMAP_TIMES_ROMAN_24);

    //test
    window << Rectangle(Vec2D(280, 280), Vec2D(300, 300), KBlue, KPurple);
    window << Circle(Vec2D(150, 150), 40, KYellow, KRed);
    window << Line(Vec2D(400, 400), Vec2D(500, 400), KRed);
    window << Triangle(Vec2D(100, 100), Vec2D(150, 100), Vec2D(100, 150), KCyan, KRed);
}
