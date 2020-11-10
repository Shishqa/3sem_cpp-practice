/*============================================================================*/
#ifndef SHISHGL_LISTENER_HPP
#define SHISHGL_LISTENER_HPP
/*============================================================================*/
#include "ShishGL/core/subscription_manager.hpp"
#include "ShishGL/core/event/system_slots.hpp"
/*============================================================================*/
namespace ShishGL {

    class Listener : public Object {
    public:

        explicit Listener(Object::ID id) : Object(id) {
            //SubscriptionManager::subscribe(SystemEvents::SYSTEM, Object::id());
        }

        virtual bool filterEvent(class Event&) const { return true; }

        ~Listener() override = default;

    protected:

        friend class Event;

        virtual bool onEvent(class Event&) { return false; }

        /* System Event handlers */
        /*-------------------------------------------------------*/
        friend class MouseEvent;
        virtual bool onMouseMove(class MouseEvent&) { return false; }

        friend class MouseButtonEvent;
        virtual bool onMouseClick(class MouseButtonEvent&) { return false; }

        friend class MouseScrollEvent;
        virtual bool onMouseScroll(class MouseScrollEvent&) { return false; }

        friend class KeyboardEvent;
        virtual bool onKeyboard(class KeyboardEvent&) { return false; }

        friend class TimerEvent;
        virtual bool onTimer(class TimerEvent&) { return false; }
        /*-------------------------------------------------------*/

    };

}
/*============================================================================*/
#endif //SHISHGL_LISTENER_HPP
/*============================================================================*/
