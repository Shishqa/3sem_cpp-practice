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

        /*====================================================================*/
        struct EmptyEvent {
        };
        /*====================================================================*/

        /*====================================================================*/
        struct MouseMoveEvent {
            Vector2<int> where;
            Mouse::CursorState state;
        };
        /*--------------------------------------------------------------------*/
        struct MouseClickEvent {
            Vector2<int> where;
            Mouse::Button button;
            Mouse::State  state;
        };
        /*--------------------------------------------------------------------*/
        struct MouseScrollEvent {
            Vector2<int> where;
            Mouse::Wheel wheel;
        };
        /*====================================================================*/


        struct KeyboardEvent {
            /* mouse position ? */
            Keyboard::Key code;
            Keyboard::State state;
            Keyboard::Modifier modifiers;
        };

        struct TimerEvent {
        };

        typedef enum {
            RENDER,
            MOUSE_CLICK,
            MOUSE_MOVE,
            MOUSE_SCROLL,
            KEYBOARD,
            TIMER
        } EventType;

        EventType type;

        union {
            EmptyEvent empty;
            MouseClickEvent mouse_button;
            MouseMoveEvent mouse_cursor;
            MouseScrollEvent mouse_wheel;
            KeyboardEvent keyboard;
            TimerEvent timer;
        };

    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
