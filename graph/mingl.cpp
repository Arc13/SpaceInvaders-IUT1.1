#include <map>

#include "mingl.h"

using namespace std;
using namespace nsUtil;

// Astuce pour faire passer les handlers en fonction static dans initGraphic()
namespace {
map<int, MinGL *> anyWindow;

template<typename T, T oHandler>
struct callBackBuilder;

template<typename Obj, typename... Arg, void(Obj::* oHandler)(Arg...)>
struct callBackBuilder<void(Obj::*)(Arg...), oHandler>
{
    static void callback(Arg... arg)
    {
        int current_id = glutGetWindow();
        //cout << "window [" << current_id << "] handler call" << endl;
        auto it = anyWindow.find(current_id);
        if (it != anyWindow.end())
        {
            (it->second->*oHandler)(arg...);
        }
    }
};
}

#define BIND_CALLBACK(HANDLER) callBackBuilder<decltype(HANDLER), HANDLER>::callback

MinGL::MinGL(const unsigned &Width, const unsigned &Height, const std::string &Name)
    : windowWidth(Width)
    , windowHeight(Height)
    , windowName(Name)
{

}

MinGL::~MinGL()
{
    auto it = anyWindow.find(glutWindowId);
    if (it != anyWindow.end())
        anyWindow.erase(it);

    stopGaphic();
}

void MinGL::updateGraphic()
{
    glutPostRedisplay();
    glutMainLoopEvent();
}

void MinGL::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void MinGL::addDrawable(std::unique_ptr<Drawable> drawable)
{
    drawStack.push_back(std::move(drawable));
}

char MinGL::getKey()
{
    glutMainLoopEvent();

    char key;
    while (keyboardBuffer.size() == 0)
    {
        glutMainLoopEvent();
    }

    key = keyboardBuffer.front();
    keyboardBuffer.pop();

    return key;
}

void MinGL::initGraphic()
{
    // Initialisation GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(int(windowWidth), int(windowHeight));
    glutInitWindowPosition(200, 100);

    glutWindowId = glutCreateWindow(windowName.c_str());
    anyWindow[glutWindowId] = this;

    // On active la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Initialisation handlers
    glutReshapeFunc(BIND_CALLBACK(&MinGL::callReshape));
    glutDisplayFunc(BIND_CALLBACK(&MinGL::callDisplay));
    glutKeyboardFunc(BIND_CALLBACK(&MinGL::callKeyboard));
    glutSpecialFunc(BIND_CALLBACK(&MinGL::callKeyboardSpecial));
    glutMouseFunc(BIND_CALLBACK(&MinGL::callMouse));

    // On set la couleur d'effacement (prend des float, donc obligé de diviser par la taille d'un GLuint)
    glClearColor(bgColor.Red / 256.f, bgColor.Green / 256.f, bgColor.Blue / 256.f, 1.f);

    // Efface écran
    clearScreen();

    // Un tour de boucle pour lancer l'affichage
    glutMainLoopEvent();
}

void MinGL::stopGaphic()
{
    glutDestroyWindow(glutWindowId);
    glutMainLoopEvent();
}

void MinGL::callReshape(int h, int w)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLfloat (windowWidth), 0.0, GLfloat (windowHeight));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, h, w);
}

void MinGL::callDisplay()
{
    clearScreen();
    glRasterPos2i(0,0);
    glShadeModel(GL_FLAT);

    for (const std::unique_ptr<Drawable> &actualDrawable : drawStack) {
        actualDrawable->Draw();
    }
    drawStack.clear();

    glFlush();
    glutSwapBuffers();
}


void MinGL::callKeyboard(unsigned char key, int x, int y)
{
    keyboardBuffer.push(key);
    cout << "keyboard [key = " << key << "; x = " << x << "; y = " << y << "]" << endl;
}

void MinGL::callKeyboardSpecial(int key, int x, int y)
{
    keyboardBuffer.push(key << 8);
}

void MinGL::callMouse(int button, int state, int x, int y)
{
    cout << "mouse [button = " << button << "; state = " << state << "; x = " << x << "; y = " << y << "]" << endl;
}

unsigned MinGL::getWindowWidth() const
{
    return windowWidth;
}

unsigned MinGL::getWindowHeight() const
{
    return windowHeight;
}

Vec2D MinGL::getWindowSize() const
{
    return Vec2D(windowWidth, windowHeight);
}
