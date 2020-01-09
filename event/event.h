/**
 * @file event.h
 * @brief Collection for various event types and data
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 09 janvier 2020
 */

#ifndef EVENT_H
#define EVENT_H

/**
 * @namespace nsEvent
 * @brief Namespace for event management
 */
namespace nsEvent {

/**
 * @brief EventType_t : List of all Event types
 */
enum EventType_t {
    MouseClick, /**< A mouse button state changed */
    MouseMove /**< The mouse moved */,
    MouseDrag, /**< The mouse moved while one of its button was pressed */

    Keyboard, /**< A key on the keyboard was pressed */
    KeyboardSpecial, /**< A special key on the keyboard was pressed */
};

/**
 * @struct MouseClickData_t
 * @brief Holds data for a MouseClick event
 */
struct MouseClickData_t {
    /**
     * @brief Constructor for the MouseClickData_t struct
     * @param[in] button_ : Mouse button
     * @param[in] state_ : State of the button
     * @param[in] x_ : X coordinate of the mouse cursor
     * @param[in] y_ : Y coordinate of the mouse cursor
     * @fn MouseClickData_t(const int &button_, const int &state_, const int &x_, const int &y_);
     */
    MouseClickData_t(const int &button_, const int &state_, const int &x_, const int &y_)
        : button(button_)
        , state(state_)
        , x(x_)
        , y(y_)
    {}

    int button; /**< Numerical ID of the button */
    int state; /**< New state of the button */
    int x; /**< X coordinate of the click, relative to the top-left corner of the window */
    int y; /**< Y coordinate of the click, relative to the top-left corner of the window */
};

/**
 * @struct MouseMoveData_t
 * @brief Holds data for a MouseMove/MouseDrag event
 */
struct MouseMoveData_t {
    /**
     * @brief Constructor for the MouseMoveData_t struct
     * @param[in] x_ : X coordinate of the mouse cursor
     * @param[in] y_ : Y coordinate of the mouse cursor
     * @fn MouseMoveData_t(const int &x_, const int &y_);
     */
    MouseMoveData_t(const int &x_, const int &y_)
        : x(x_)
        , y(y_)
    {}

    int x; /**< X coordinate of the new mouse position, relative to the top-left corner of the window */
    int y; /**< Y coordinate of the new mouse position, relative to the top-left corner of the window */
};

/**
 * @struct KeyboardData_t
 * @brief Holds data for a Keyboard event
 */
struct KeyboardData_t {
    /**
     * @brief Constructor for the KeyboardData_t struct
     * @param[in] key_ : Character of the key
     * @param[in] x_ : X coordinate of the mouse cursor
     * @param[in] y_ : Y coordinate of the mouse cursor
     * @fn KeyboardData_t(const unsigned char &key_, const int &x_, const int &y_);
     */
    KeyboardData_t(const unsigned char &key_, const int &x_, const int &y_)
        : key(key_)
        , x(x_)
        , y(y_)
    {}

    unsigned char key; /**< The character of the pressed key */
    int x; /**< X coordinate of the mouse position, relative to the top-left corner of the window */
    int y; /**< Y coordinate of the mouse position, relative to the top-left corner of the window */
};

/**
 * @struct KeyboardSpecialData_t
 * @brief Holds data for a KeyboardSpecial event
 */
struct KeyboardSpecialData_t {
    /**
     * @brief Constructor for the KeyboardSpecialData_t struct
     * @param[in] key_ : ID of the special key
     * @param[in] x_ : X coordinate of the mouse cursor
     * @param[in] y_ : Y coordinate of the mouse cursor
     * @fn KeyboardSpecialData_t(const int &key_, const int &x_, const int &y_);
     */
    KeyboardSpecialData_t(const int &key_, const int &x_, const int &y_)
        : key(key_)
        , x(x_)
        , y(y_)
    {}

    int key; /**< The ID of the pressed special key */
    int x; /**< X coordinate of the mouse position, relative to the top-left corner of the window */
    int y; /**< Y coordinate of the mouse position, relative to the top-left corner of the window */
};

/**
 * @union EventData_t
 * @brief Union containing the data for an event
 */
union EventData_t {
    MouseClickData_t clickData; /**< Data for a MouseClick event */
    MouseMoveData_t moveData; /**< Data for a MouseMove/MouseDrag event */
    KeyboardData_t keyboardData; /**< Data for a Keyboard event */
    KeyboardSpecialData_t keyboardSpecialData; /**< Data for a KeyboardSpecial event */
};

/**
 * @struct Event_t
 * @brief Holds data for an event
 */
struct Event_t {
    /**
     * @brief Constructor for the Event_t struct
     * @param[in] eventType_ : Event type
     * @param[in] eventData_ : Event data
     * @fn Event_t(const EventType_t &eventType_, const EventData_t &eventData_);
     */
    Event_t(const EventType_t &eventType_, const EventData_t &eventData_)
        : eventType(eventType_)
        , eventData(eventData_)
    {}

    EventType_t eventType; /**< Type of the event */
    EventData_t eventData; /**< Data of the event */
};

} // namespace nsEvent

#endif // EVENT_H
