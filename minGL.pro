TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    event/event_manager.cpp \
    figs/basefig.cpp \
    figs/circle.cpp \
    figs/figure.cpp \
    figs/line.cpp \
    figs/rectangle.cpp \
    figs/triangle.cpp \
    game.cpp \
    graph/mingl.cpp \
    graph/rgbacolor.cpp \
    gui/star_background.cpp \
    gui/text.cpp \
    screen/iscreen.cpp \
    screen/main_menu.cpp \
    screen/screen_id_map.cpp \
    tools/CException.cxx \
    tools/glut_font.cpp \
    tools/myexception.cpp \
    tools/tools.cpp \
    tools/pixelexception.cpp

QT += opengl core gui

#LIBS +=  -lglut -lGLU -lGL -lGLEW
LIBS +=  -lglut -lGLU -lGL

#INCLUDEPATH += /opt/local/include/GL/
INCLUDEPATH += /usr/include/GL/

QMAKE_CXXFLAGS += -Wall

HEADERS += \
    event/event.h \
    event/event_manager.h \
    figs/basefig.h \
    figs/circle.h \
    figs/figure.h \
    figs/line.h \
    figs/rectangle.h \
    figs/triangle.h \
    game.h \
    graph/idrawable.h \
    graph/libgraphique_fonts.h \
    graph/mingl.h \
    graph/rgbacolor.h \
    graph/vec2d.h \
    gui/star_background.h \
    gui/text.h \
    screen/iscreen.h \
    screen/main_menu.h \
    screen/screen_id_map.h \
    screen/screen_identifiers.h \
    tools/CException.h \
    tools/CException.hxx \
    tools/CstCodErr.h \
    tools/IEditable.h \
    tools/IEditable.hxx \
    tools/glut_font.h \
    tools/myexception.h \
    tools/pixel.h \
    tools/tools.h \
    graph/iminglinjectable.h \
    tools/pixelexception.h
