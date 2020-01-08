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
#include "graph/rgbcolor.h"
#include "graph/vec2d.h"
#include "figs/rectangle.h"
#include "figs/triangle.h"
#include "figs/circle.h"
#include "figs/figure.h"

using namespace std;

void displayFramerate(const chrono::milliseconds FrameTime, MinGL &Window)
{
    const string framerateStr = to_string(1 / (FrameTime.count() / 1000.f));
    Window << GuiText(Vec2D(5, Window.getWindowHeight() - 15), framerateStr + " FPS", KPurple);
}

void Game()
{
    // Initialise le système graphique
    MinGL Window;
    Window.initGlut();
    Window.initGraphic();

    GuiStarBackground starBackground(300, Window.getWindowSize());

    chrono::milliseconds frameTime;
    while (true)
    {
        // Récupère l'heure au début de la boucle
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

        // Efface l'écran a chaque itération
        Window.clearScreen();

        // On met a jour et affiche le fond étoilé
        starBackground.Update(frameTime);
        Window << starBackground;

        // On injecte tout ce qui doit être affiché
        Window << GuiText(Vec2D(10, 10), "BITMAP 8x13", KRed);
        Window << GuiText(Vec2D(10, 25), "BITMAP 9x15", KRed, GlutFont::BITMAP_9_BY_15);
        Window << GuiText(Vec2D(10, 40), "HELVETICA 10", KBlue, GlutFont::BITMAP_HELVETICA_10);
        Window << GuiText(Vec2D(10, 55), "HELVETICA 12", KBlue, GlutFont::BITMAP_HELVETICA_12);
        Window << GuiText(Vec2D(10, 75), "HELVETICA 18", KBlue, GlutFont::BITMAP_HELVETICA_18);
        Window << GuiText(Vec2D(10, 95), "TIMES NEW ROMAN 10", KGreen, GlutFont::BITMAP_TIMES_ROMAN_10);
        Window << GuiText(Vec2D(10, 115), "TIMES NEW ROMAN 24", KGreen, GlutFont::BITMAP_TIMES_ROMAN_24);

        //test
        Window << Rectangle(Vec2D(50, 50), Vec2D(20, 20), KRed) * 2;

        // Affiche le framerate
        displayFramerate(frameTime, Window);

        // On met a jour la fenêtre
        Window.updateGraphic();

        /*
         * Récupère l'heure a la fin de la boucle
         * pour calculer la durée de calcul d'une image
         */
        frameTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start);
    }
}
