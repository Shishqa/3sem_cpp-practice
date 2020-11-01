/*============================================================================*/
#ifndef SHISHGL_BASE_EVENT_HPP
#define SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
#include "ShishGL/core/input/timer.hpp"
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Event {
    public:

        enum Type {
            NONE = 0,
            RENDER,
            MOUSE_BUTTON,
            MOUSE_SCROLL,
            MOUSE_MOVE,
            KBD_BUTTON,
            TIMER,
            IDLE,
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

    /*------------------------------------------------------------------------*/

    class SlideEvent : public Event {
    public:

        SlideEvent(Event::Type type, double delta)
            : Event(type)
            , e_delta(delta) {}

        ~SlideEvent() override = default;

        [[nodiscard]]
        inline double delta() const { return e_delta; }

    protected:

        double e_delta;

    };

    /*------------------------------------------------------------------------*/

    class TimerEvent : public Event {
    public:

        TimerEvent(Event::Type type, const TimeDelta& delta)
            : Event(type)
            , time_delta(delta) {}

        ~TimerEvent() override = default;

        [[nodiscard]]
        inline const TimeDelta& delta() const { return time_delta; }

    protected:

        TimeDelta time_delta;

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
