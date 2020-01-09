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

#include "gui/gui_star_background.h"
#include "gui/gui_text.h"

#include "screen/screen_id_map.h"
#include "screen/screen_main_menu.h"

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

    // Initialise la gestion des écrans sur le menu principal
    std::unique_ptr<IScreen> currentScreen = std::unique_ptr<ScreenMainMenu>(new ScreenMainMenu());

    // On instancie le background
    GuiStarBackground starBackground(300, Window.getWindowSize());

    chrono::duration<float> frameTime;
    while (true)
    {
        // Récupère l'heure au début de la boucle
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

        // Efface l'écran a chaque itération
        Window.clearScreen();

        // Change d'écran si l'écran actuel le requête
        const ScreenIdentifiers screenChangeId = currentScreen->getRequestedScreenChange();
        if (screenChangeId != ScreenIdentifiers::None)
            currentScreen = unique_ptr<IScreen>(ScreenIdMap::getScreenFromId(screenChangeId));

        // On vérifie pour de nouveaux événements
        while (Window.getEventManager().hasEvent())
            currentScreen->processEvent(Window.getEventManager().pullEvent());

        // Met a jour et affiche le fond étoilé
        starBackground.Update(frameTime.count());
        Window << starBackground;

        // Met a jour l'écran actuel
        currentScreen->update(frameTime.count());

        // Affiche l'écran actuel
        currentScreen->draw(Window);

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
