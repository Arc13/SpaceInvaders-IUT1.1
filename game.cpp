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

#include "gui/star_background.h"
#include "gui/text.h"

#include "screen/screen_id_map.h"
#include "screen/main_menu.h"

using namespace std;

void displayFramerate(const float &frameTime, MinGL &window)
{
    const string framerateStr = to_string(1 / (frameTime / 1000.f));
    window << nsGui::Text(Vec2D(5, 15), framerateStr + " FPS", KPurple);
} // displayFramerate

void game()
{
    // Initialise the graphics and event systems
    MinGL Window;
    Window.initGlut();
    Window.initGraphic();

    // Initialise the screen management
    std::unique_ptr<nsScreen::IScreen> currentScreen = std::unique_ptr<nsScreen::MainMenu>(new nsScreen::MainMenu());

    // Create the star background for the entire screen
    nsGui::StarBackground starBackground(300, Window.getWindowSize());

    chrono::duration<float> frameTime;
    while (true)
    {
        // Gets system clock at the beginning of the loop
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

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
        currentScreen->update(frameTime.count());

        // Draw the actual screen
        currentScreen->draw(Window);

        // Display the framerate
        displayFramerate(frameTime.count(), Window);

        // Push frame to the window
        Window.updateGraphic();

        // Get system time at the end to compute rendering time
        frameTime = chrono::system_clock::now() - start;
    } // Game()
}
