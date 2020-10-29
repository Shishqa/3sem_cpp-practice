/*============================================================================*/
#ifndef SHISHGL_BASE_EVENT_HPP
#define SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Event {
    public:

        enum Type {
            NONE = 0,
            TIMER,
            RENDER,
            MOUSE_BUTTON,
            MOUSE_SCROLL,
            MOUSE_MOVE,
            KBD_BUTTON,
            SLIDE,

            USER_MIN = 100,
            /* USER TYPES */
            USER_MAX = 255
        };

        explicit Event(Event::Type type)
            : e_type(type) {}

        [[nodiscard]]
        inline Type type() const { return static_cast<Type>(e_type); }

        virtual ~Event() = default;

    protected:

        uint8_t e_type;

    };

}
/*============================================================================*/



    /*------------------------------------------------------------------------*/
//
//    struct Event {
//
//        /* Mouse */
//        /*====================================================================*/
//        struct MouseEvent {
//            Vector2<int> where;
//        };
//        /*--------------------------------------------------------------------*/
//        struct MouseMoveEvent : public MouseEvent {
//        };
//        /*--------------------------------------------------------------------*/
//        struct MouseClickEvent : public MouseEvent {
//            Mouse::Button button;
//            Mouse::State  state;
//        };
//        /*--------------------------------------------------------------------*/
//        struct MouseScrollEvent : public MouseEvent {
//            double delta;
//        };
//        /*====================================================================*/
//
//        /* Keyboard */
//        /*====================================================================*/
//        struct KeyboardEvent {
//            /* mouse position ? */
//            Keyboard::Key code;
//            Keyboard::State state;
//            Keyboard::Modifier modifiers;
//        };
//        /*====================================================================*/
//
//        /* Timer */
//        /*====================================================================*/
//        struct TimerEvent {
//            /* TODO */
//        };
//        /*====================================================================*/
//
//        typedef enum {
//            NONE,    /* https://youtu.be/JCwS3lGxJCU */
//            RENDER,
//            MOUSE_CLICK,
//            MOUSE_MOVE,
//            MOUSE_SCROLL,
//            KEYBOARD,
//            TIMER,
//
//            USER_MIN = 100,
//            /* USER_EVENTS */
//            USER_MAX = 200
//
//        } EventType;
//
//        /* Public data */
//        /*====================================================================*/
//        EventType type;
//        union {
//            MouseEvent mouse;
//            MouseClickEvent mouse_button;
//            MouseMoveEvent mouse_cursor;
//            MouseScrollEvent mouse_wheel;
//            KeyboardEvent keyboard;
//            TimerEvent timer;
//        };
//        /*====================================================================*/
//
//    };


/*============================================================================*/
#endif //SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
