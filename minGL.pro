TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    config/config.cpp \
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
    game/manager.cpp \
    gui/button.cpp \
    gui/star_background.cpp \
    gui/text.cpp \
    score/score_mgr.cpp \
    screen/config_utility.cpp \
    screen/end_game.cpp \
    screen/iscreen.cpp \
    screen/main_game.cpp \
    screen/screen_id_map.cpp \
    screen/title_menu.cpp \
    screen/top_scores.cpp \
    tools/CException.cxx \
    tools/glut_font.cpp \
    tools/myexception.cpp \
    tools/tools.cpp \
    tools/pixelexception.cpp \
    transition/transition.cpp \
    transition/transition_contract.cpp \
    transition/transition_engine.cpp

QT += opengl core gui

#LIBS +=  -lglut -lGLU -lGL -lGLEW
LIBS +=  -lglut -lGLU -lGL

#INCLUDEPATH += /opt/local/include/GL/
INCLUDEPATH += /usr/include/GL/

QMAKE_CXXFLAGS += -Wall

HEADERS += \
    config/config.h \
    event/event.hpp \
    event/event_manager.h \
    figs/basefig.h \
    figs/circle.h \
    figs/figure.h \
    figs/line.h \
    figs/rectangle.h \
    figs/triangle.h \
    game.h \
    game/difficulty.hpp \
    graph/idrawable.h \
    graph/libgraphique_fonts.h \
    graph/mingl.h \
    graph/rgbacolor.h \
    graph/vec2d.h \
    game/manager.h \
    game/manager_const.h \
    game/manager_type.h \
    gui/button.h \
    gui/star_background.h \
    gui/text.h \
    score/score_mgr.h \
    score/score_mgr.hxx \
    screen/config_utility.h \
    screen/end_game.h \
    screen/iscreen.h \
    screen/main_game.h \
    screen/screen_id_map.h \
    screen/screen_identifiers.h \
    screen/title_menu.h \
    screen/top_scores.h \
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
    tools/pixelexception.h \
    transition/itransitionable.h \
    transition/transition.h \
    transition/transition_contract.h \
    transition/transition_engine.h \
    transition/transition_types.h
