/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
namespace ShishGL {

    class Object {
    public:

        Object(const Object& other) = delete;

        Object& operator=(const Object& other) = delete;

        virtual ~Object() = default;

        /* Event handlers */
        /*--------------------------------------------------------------------*/
        virtual bool onMouseMove(const class MouseEvent* event) { return false; }

        virtual bool onMouseClick(const class MouseButtonEvent* event) { return false; }

        virtual bool onMouseScroll(const class MouseScrollEvent* event) { return false; }

        virtual bool onKeyboard(const class KeyboardEvent* event) { return false; }

        virtual bool onTimer(const class TimerEvent* event) { return false; }

        virtual bool onIdle(const class TimerEvent* event) { return false; }

        virtual bool unhandledEvent(const class Event* event) { return false; }
        /*--------------------------------------------------------------------*/

    protected:

        Object() = default;

        /* delivers events */
        friend class EventSystem;

        /* creates objects */
        friend class CoreApplication;

        /* > return true if you wish to receive this event or
         *   false if you don't
         * override for filtering some events
         * default: always return true */
        virtual bool filterEvent(const class Event* event) { return true; }

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
