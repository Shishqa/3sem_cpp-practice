/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include <cstdint>
#include <ctime>

#include "ShishGL/utility/input.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    /*------------------------------------------------------------------------*/
    struct Event {

        /* Mouse */
        /*====================================================================*/
        struct MouseEvent {
            Vector2<int> where;
        };
        /*--------------------------------------------------------------------*/
        struct MouseMoveEvent : public MouseEvent {
        };
        /*--------------------------------------------------------------------*/
        struct MouseClickEvent : public MouseEvent {
            Mouse::Button button;
            Mouse::State  state;
        };
        /*--------------------------------------------------------------------*/
        struct MouseScrollEvent : public MouseEvent {
            double delta;
        };
        /*====================================================================*/

        /* Keyboard */
        /*====================================================================*/
        struct KeyboardEvent {
            /* mouse position ? */
            Keyboard::Key code;
            Keyboard::State state;
            Keyboard::Modifier modifiers;
        };
        /*====================================================================*/

        /* Timer */
        /*====================================================================*/
        struct TimerEvent {
            /* TODO */
        };
        /*====================================================================*/

        typedef enum {
            NONE,    /* https://youtu.be/JCwS3lGxJCU */
            RENDER,
            MOUSE_CLICK,
            MOUSE_MOVE,
            MOUSE_SCROLL,
            KEYBOARD,
            TIMER,

            USER_MIN = 100,
            /* USER_EVENTS */
            USER_MAX = 200

        } EventType;

        /* Public data */
        /*====================================================================*/
        EventType type;
        union {
            MouseEvent mouse;
            MouseClickEvent mouse_button;
            MouseMoveEvent mouse_cursor;
            MouseScrollEvent mouse_wheel;
            KeyboardEvent keyboard;
            TimerEvent timer;
        };
        /*====================================================================*/

    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
