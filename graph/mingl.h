#ifndef MINGL_H
#define MINGL_H

#include <string>
#include <vector>
#include <queue>
#include <memory> // shared_ptr

#include "freeglut.h"

#include "idrawable.h"
#include "libgraphique_fonts.h"
#include "rgbacolor.h"

#include "../graph/vec2d.h"

#include "../event/event_manager.h"
#include "../tools/myexception.h"
#include "../tools/pixelexception.h"

/*!
 * \brief The minGL class
 *          sert de classe de base à tout le bordel
 */

// Pour les polices et l'affichage des chaines de caractères, voir: https://www.opengl.org/resources/libraries/glut/spec3/node76.html

class MinGL
{
private:
    // Les données membres en tant que tel
    const Vec2D windowSize;
    const std::string windowName;
    std::shared_ptr<font> windowFont = std::make_shared<font>(FONT_HELVETICA_10);
    RGBAcolor fontColor = KWhite;
    RGBAcolor bgColor = RGBAcolor(17, 17, 17);


    // Ce dont on a besoin pour Glut
    short glutWindowId = 0;
    std::vector<std::unique_ptr<IDrawable>> drawStack;


    // Les handlers
    Event::EventManager eventManager;
    void callReshape(int h, int w);
    void callDisplay();
    void callMouse(int button, int state, int x = 0, int y = 0);
    void callMotion(int x, int y);
    void callPassiveMotion(int x, int y);
    void callKeyboard(unsigned char key, int x = 0, int y = 0);
    void callKeyboardSpecial(int key, int x = 0, int y = 0);

public:
    static void initGlut()
    {
        int tmp=0;
        glutInit(&tmp, NULL);

    }

    void initGraphic();
    void stopGaphic();

    MinGL(const std::string &name_ = std::string(), const Vec2D &windowSize_ = Vec2D(640, 480));
    ~MinGL();

    void addDrawable(std::unique_ptr<IDrawable> drawable);
    void updateGraphic();
    void clearScreen();

    Event::EventManager &getEventManager();

    const Vec2D getWindowSize() const;

};

#endif // MINGL_H
