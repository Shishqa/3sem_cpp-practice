/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include "Listener.hpp"
/*============================================================================*/
namespace ShishGL {

    class Event {
    protected:

        Event() = default;

        virtual bool happen(Listener* listener);

        virtual ~Event() = default;

        friend class EventSystem;
        friend class EventManager;
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
