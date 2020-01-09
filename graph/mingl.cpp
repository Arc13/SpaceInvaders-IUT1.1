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

MinGL::MinGL(const std::string &name_, const Vec2D &windowSize_)
    : windowSize(windowSize_)
    , windowName(name_)
    , eventManager()
{

}

MinGL::~MinGL()
{
    auto it = anyWindow.find(glutWindowId);
    if (it != anyWindow.end())
        anyWindow.erase(it);

    stopGaphic();
}

void MinGL::addDrawable(std::unique_ptr<IDrawable> drawable)
{
    drawStack.push_back(std::move(drawable));
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

Event::EventManager &MinGL::getEventManager()
{
    return eventManager;
}

void MinGL::initGraphic()
{
    // Initialisation GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(int(windowSize.x), int(windowSize.y));
    glutInitWindowPosition(200, 100);

    glutWindowId = glutCreateWindow(windowName.c_str());
    anyWindow[glutWindowId] = this;

    // On active la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Initialisation handlers
    glutReshapeFunc(BIND_CALLBACK(&MinGL::callReshape));
    glutDisplayFunc(BIND_CALLBACK(&MinGL::callDisplay));
    glutMouseFunc(BIND_CALLBACK(&MinGL::callMouse));
    glutMotionFunc(BIND_CALLBACK(&MinGL::callMotion));
    glutPassiveMotionFunc(BIND_CALLBACK(&MinGL::callPassiveMotion));
    glutKeyboardFunc(BIND_CALLBACK(&MinGL::callKeyboard));
    glutSpecialFunc(BIND_CALLBACK(&MinGL::callKeyboardSpecial));

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
    gluOrtho2D(0.0, GLfloat (windowSize.x), GLfloat (windowSize.y), 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, h, w);
}

void MinGL::callDisplay()
{
    clearScreen();
    glRasterPos2i(0,0);
    glShadeModel(GL_FLAT);

    for (const std::unique_ptr<IDrawable> &actualDrawable : drawStack) {
        actualDrawable->Draw();
    }
    drawStack.clear();

    glFlush();
    glutSwapBuffers();
}


void MinGL::callMouse(int button, int state, int x, int y)
{
    eventManager.pushEvent(Event::Event(Event::EventType_t::MouseClick, {.clickData = Event::MouseClickData_t(button, state, x, y)}));
}

void MinGL::callMotion(int x, int y)
{
    eventManager.pushEvent(Event::Event(Event::EventType_t::MouseDrag, {.moveData = Event::MouseMoveData_t(x, y)}));
}

void MinGL::callPassiveMotion(int x, int y)
{
    eventManager.pushEvent(Event::Event(Event::EventType_t::MouseMove, {.moveData = Event::MouseMoveData_t(x, y)}));
}

void MinGL::callKeyboard(unsigned char key, int x, int y)
{
    eventManager.pushEvent(Event::Event(Event::EventType_t::Keyboard, {.keyboardData = Event::KeyboardData_t(key, x, y)}));
}

void MinGL::callKeyboardSpecial(int key, int x, int y)
{
    eventManager.pushEvent(Event::Event(Event::EventType_t::KeyboardSpecial, {.keyboardSpecialData = Event::KeyboardSpecialData_t(key, x, y)}));
}

const Vec2D MinGL::getWindowSize() const
{
    return windowSize;
}
