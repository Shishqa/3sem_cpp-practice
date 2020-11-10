/*============================================================================*/
#ifndef SHISHGL_BASE_EVENT_HPP
#define SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
#include "ObjectManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class Event {
    protected:

        friend class EventSystem;

        Event() = default;

        virtual bool happen(Object::ID object);

        virtual ~Event() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
