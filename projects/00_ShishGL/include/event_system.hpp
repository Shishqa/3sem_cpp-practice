/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/

#include <queue>

#include "object.hpp"
#include "event.hpp"

/*============================================================================*/

namespace ShishGL {

    struct EventBind {
        const Event* event;
        Object* target;
    };

    /*------------------------------------------------------------------------*/

    class EventBuffer {
    public:

        EventBuffer() = default;

        EventBuffer(const EventBuffer& other) = delete;

        EventBuffer& operator=(const EventBuffer& other) = delete;

        virtual ~EventBuffer() = default;

        //void postEvent(Object* target, const Event* event);

        //void flush();

    private:

        using EventQueue = std::queue<EventBind>;

        EventQueue events;
    };

    /*------------------------------------------------------------------------*/

    class EventSystem {
    public:

        ~EventSystem() = default;

        //static void sendEvent(Object* target, const Event* event);

        //static void postEvent(const Event* event);

    private:

        EventSystem() = default;

        //static EventBuffer& Events();

        //static void processNewEvents();
    };
}

/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
