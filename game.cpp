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

#include <thread>

#include "game.h"

#include "gui/star_background.h"
#include "gui/text.h"

#include "screen/screen_id_map.h"
#include "screen/main_menu.h"

#define FPS_LIMIT 60

using namespace std;

void displayFramerate(const std::chrono::microseconds &frameTime, MinGL &window)
{
    const string framerateStr = to_string(1 / (frameTime.count() / 1000000.f));
    window << nsGui::Text(Vec2D(5, 15), framerateStr + " FPS", KPurple);
} // displayFramerate()

void game()
{
    // Initialise the graphics and event systems
    MinGL Window("Space Outvaders");
    Window.initGlut();
    Window.initGraphic();

    // Initialise the screen management
    std::unique_ptr<nsScreen::IScreen> currentScreen = std::unique_ptr<nsScreen::MainMenu>(new nsScreen::MainMenu());

    // Create the star background for the entire screen
    nsGui::StarBackground starBackground(300, Window.getWindowSize());

    chrono::microseconds frameTime;
    while (true)
    {
        // Gets system clock at the beginning of the loop
        chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();

        // Clear screen each frame
        Window.clearScreen();

        // Switch screen if the actual one requests it
        const nsScreen::ScreenIdentifiers screenChangeId = currentScreen->getRequestedScreenChange();
        if (screenChangeId != nsScreen::ScreenIdentifiers::ID_None)
            currentScreen = unique_ptr<nsScreen::IScreen>(nsScreen::ScreenIdMap::getScreenFromId(screenChangeId));

        // Check for new events (user inputs)
        while (Window.getEventManager().hasEvent())
            currentScreen->processEvent(Window.getEventManager().pullEvent());

        // Update and draw the star background
        starBackground.update(frameTime.count());
        Window << starBackground;

        // Update the actual screen
        currentScreen->update(frameTime);

        // Draw the actual screen
        currentScreen->draw(Window);

        // Display the framerate
        displayFramerate(frameTime, Window);

        // Push frame to the window
        Window.updateGraphic();

        // Wait a bit to limit the framerate and let the CPU relax
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start));

        // Get system time at the end to compute rendering time
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    } // Game()
}
