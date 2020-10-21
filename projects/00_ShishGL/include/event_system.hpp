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

    class EventBuffer {
    public:

        EventBuffer() = default;

        EventBuffer(const EventBuffer& other) = delete;

        EventBuffer& operator=(const EventBuffer& other) = delete;

        virtual ~EventBuffer();

        void postEvent(Object* target, const Event* event) {
            events.push(EventBind{event, target});
        }

        void sendEvent(Object* target, const Event* event) {
            target->getEvent(event);
        }

        void flush() {
            const EventBind event = events.front();
                                    events.pop();
            return event_p;
        }

    private:

        using EventQueue = std::queue<EventBind>;

        EventQueue events;

    };

    class EventSystem {
    public:

        ~EventSystem() = default;

    private:

        EventSystem()  = default;

        using EventQueue = std::queue<const Event*>;

        static EventQueue& Events();

        static void processNewEvents();

        friend Object;
        friend WindowManager;
    };
}

/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
