#ifndef EVENT_H
#define EVENT_H

namespace Event {

enum EventType_t {
    MouseClick,
    MouseMove,
    MouseDrag,

    Keyboard,
    KeyboardSpecial,
};

struct MouseClickData_t {
    MouseClickData_t(int button_, int state_, int x_, int y_)
        : button(button_)
        , state(state_)
        , x(x_)
        , y(y_)
    {}

    int button;
    int state;
    int x;
    int y;
};

struct MouseMoveData_t {
    MouseMoveData_t(int x_, int y_)
        : x(x_)
        , y(y_)
    {}

    int x;
    int y;
};

struct KeyboardData_t {
    KeyboardData_t(unsigned char key_, int x_, int y_)
        : key(key_)
        , x(x_)
        , y(y_)
    {}

    unsigned char key;
    int x;
    int y;
};

struct KeyboardSpecialData_t {
    KeyboardSpecialData_t(int key_, int x_, int y_)
        : key(key_)
        , x(x_)
        , y(y_)
    {}

    int key;
    int x;
    int y;
};

union EventData {
    MouseClickData_t clickData;
    MouseMoveData_t moveData;
    KeyboardData_t keyboardData;
    KeyboardSpecialData_t keyboardSpecialData;
};

struct Event {
    Event(EventType_t eventType_, EventData eventData_)
        : eventType(eventType_)
        , eventData(eventData_)
    {}

    EventType_t eventType;
    EventData eventData;
};

} // namespace Event

#endif // EVENT_H
