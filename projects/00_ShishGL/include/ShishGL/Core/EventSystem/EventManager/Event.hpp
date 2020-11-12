/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include "ObjectManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class Event {
    protected:

        Event() = default;

        virtual bool happen(Object::ID object);

        virtual ~Event() = default;

        friend class EventSystem;
        friend class EventManager;
    };

}
/*============================================================================*/
#endif //SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
