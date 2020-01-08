#ifndef MINGL_H
#define MINGL_H

#include <string>
#include <vector>
#include <queue>
#include <memory> // shared_ptr

#include "freeglut.h"

#include "drawable.h"
#include "libgraphique_fonts.h"
#include "rgbcolor.h"
#include "text.h"

#include "../tools/myexception.h"
#include "../graph/vec2d.h"

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
    const unsigned windowWidth;
    const unsigned windowHeight;
    const std::string windowName;
    std::shared_ptr<font> windowFont = std::make_shared<font>(FONT_HELVETICA_10);
    RGBcolor fontColor = KWhite;
    RGBcolor bgColor = RGBcolor(17, 17, 17);


    // Ce dont on a besoin pour Glut
    short glutWindowId = 0;
    std::vector<std::unique_ptr<Drawable>> drawStack;
    std::queue<char> keyboardBuffer;


    // Les handlers
    void callReshape(int h, int w);
    void callDisplay();
    void callKeyboard(unsigned char key, int x = 0, int y = 0);
    void callKeyboardSpecial(int key, int x = 0, int y = 0);
    void callMouse(int button, int state, int x = 0, int y = 0);

public:
    static void initGlut()
    {
        int tmp=0;
        glutInit(&tmp, NULL);

    }

    void initGraphic();
    void stopGaphic();

    MinGL(const unsigned &Width = 640, const unsigned &Height = 480, const std::string &Name = std::string());
    ~MinGL();

    void updateGraphic();
    void clearScreen();

    void addDrawable(std::unique_ptr<Drawable> drawable);

    char getKey();

    unsigned getWindowWidth() const;
    unsigned getWindowHeight() const;
    Vec2D getWindowSize() const;

};

#endif // MINGL_H
