TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figs/basefig.cpp \
    figs/circle.cpp \
    figs/figure.cpp \
    figs/line.cpp \
    figs/rectangle.cpp \
    figs/triangle.cpp \
    game.cpp \
    graph/mingl.cpp \
    graph/rgbcolor.cpp \
    gui/gui_star_background.cpp \
    gui/gui_text.cpp \
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
    figs/basefig.h \
    figs/circle.h \
    figs/figure.h \
    figs/line.h \
    figs/rectangle.h \
    figs/triangle.h \
    game.h \
    graph/drawable.h \
    graph/libgraphique_fonts.h \
    graph/mingl.h \
    graph/rgbcolor.h \
    graph/vec2d.h \
    gui/gui_star_background.h \
    gui/gui_text.h \
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
