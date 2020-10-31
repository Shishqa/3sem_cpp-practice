/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
namespace ShishGL {

/* needed for getEvent() */
/*----------------------------------------------------------------------------*/
#define CHECK_EVENT( SomeEventClass, event, handler ) {          \
    auto converted = dynamic_cast<const SomeEventClass*>(event); \
    return (converted ? this->handler(converted) : false);       \
}
/*----------------------------------------------------------------------------*/

    class Object {
    public:

        Object(const Object& other) = delete;

        Object& operator=(const Object& other) = delete;

        virtual ~Object() = default;

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
        virtual bool filterEvent(const Event* event);

        /* > calls suitable handler from defined below
         *   return true if event received */
        virtual bool getEvent(const Event* event);

        /* Event handlers */
        /*-------------------------------------------------------*/
        virtual bool onMouseMove(const MouseEvent* event);

        virtual bool onMouseClick(const MouseButtonEvent* event);

        virtual bool onMouseScroll(const MouseScrollEvent* event);

        virtual bool onKeyboard(const KeyboardEvent* event);

        virtual bool unhandledEvent(const Event* event);
        /*-------------------------------------------------------*/

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
