/*============================================================================*/
#ifndef SHISHGL_BASE_EVENT_HPP
#define SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
#include "ShishGL/core/input/timer.hpp"
#include "ShishGL/core/object/listener.hpp"
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Event {
    protected:

        friend class EventSystem;

        Event() = default;

        virtual bool happen(Object::ID listener) {
            return ObjectManager::get<Listener>(listener).onEvent(*this);
        }

        virtual ~Event() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
