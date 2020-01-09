/*!
 * \file game.cpp
 * \brief Game entry point
 * \author SOLLIER Alexandre
 * \author LAUGIER Colin
 * \author PALATUIK Alison
 * \author AMBAUD Marc
 * \version 1.0
 * \date 28 décembre 2019
 */

#include "game.h"

#include "gui/gui_text.h"
#include "gui/gui_star_background.h"
#include "graph/rgbacolor.h"
#include "graph/vec2d.h"
#include "figs/line.h"
#include "figs/rectangle.h"
#include "figs/triangle.h"
#include "figs/circle.h"
#include "figs/figure.h"

using namespace std;

void displayFramerate(const float &FrameTime, MinGL &Window)
{
    const string framerateStr = to_string(1 / (FrameTime / 1000.f));
    Window << GuiText(Vec2D(5, 15), framerateStr + " FPS", KPurple);
}

void Game()
{
    // Initialise le système graphique et d'évènements
    MinGL Window;
    Window.initGlut();
    Window.initGraphic();

    // On instancie le background
    GuiStarBackground starBackground(300, Window.getWindowSize());

    chrono::duration<float> frameTime;
    while (true)
    {
        // Récupère l'heure au début de la boucle
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

        // Efface l'écran a chaque itération
        Window.clearScreen();

        // On vérifie pour de nouveaux événements
        /*while (Window.getEventManager().hasEvent()) {
            const Event::Event currentEvent = Window.getEventManager().pullEvent();
            if (currentEvent.eventType == Event::MouseClick) {
                cout << "click: " << currentEvent.eventData.clickData.x << ", " << currentEvent.eventData.clickData.y << endl;
            } else if (currentEvent.eventType == Event::MouseMove) {
                cout << "move: " << currentEvent.eventData.moveData.x << ", " << currentEvent.eventData.moveData.y << endl;
            }
        }*/

        // On met a jour et affiche le fond étoilé
        starBackground.Update(frameTime.count());
        Window << starBackground;

        // On injecte tout ce qui doit être affiché
        Window << GuiText(Vec2D(10, 110), "BITMAP 8x13", KRed);
        Window << GuiText(Vec2D(10, 125), "BITMAP 9x15", KRed, GlutFont::BITMAP_9_BY_15);
        Window << GuiText(Vec2D(10, 140), "HELVETICA 10", KBlue, GlutFont::BITMAP_HELVETICA_10);
        Window << GuiText(Vec2D(10, 155), "HELVETICA 12", KBlue, GlutFont::BITMAP_HELVETICA_12);
        Window << GuiText(Vec2D(10, 175), "HELVETICA 18", KBlue, GlutFont::BITMAP_HELVETICA_18);
        Window << GuiText(Vec2D(10, 195), "TIMES NEW ROMAN 10", KGreen, GlutFont::BITMAP_TIMES_ROMAN_10);
        Window << GuiText(Vec2D(10, 215), "TIMES NEW ROMAN 24", KGreen, GlutFont::BITMAP_TIMES_ROMAN_24);

        //test
        Window << Rectangle(Vec2D(280, 280), Vec2D(300, 300), KBlue, KPurple);
        Window << Circle(Vec2D(150, 150), 40, KYellow, KRed);
        Window << Line(Vec2D(400, 400), Vec2D(500, 400), KRed);
        Window << Triangle(Vec2D(100, 100), Vec2D(150, 100), Vec2D(100, 150), KCyan, KRed);

        // Affiche le framerate
        displayFramerate(frameTime.count(), Window);

        // On met a jour la fenêtre
        Window.updateGraphic();

        /*
         * Récupère l'heure a la fin de la boucle
         * pour calculer la durée de calcul d'une image
         */
        frameTime = chrono::system_clock::now() - start;
    }
}
