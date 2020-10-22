/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include <queue>

#include "ShishGL/engine.hpp"
#include "ShishGL/object.hpp"
#include "event_buffer.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    public:

        ~EventSystem() = default;

        template <typename SomeEvent, typename... Args>
        static void postEvent(Args... args) {
            Events().postEvent<SomeEvent>(std::forward<Args>(args)...);
        }

        /*
        template <typename SomeEvent, typename... Args>
        static void sendEvent(Object* target, Args... args) {

            auto event = new SomeEvent(std::forward<Args>(args)...);

            target->getEvent(event);

            delete event;
        }
        */

    private:

        EventSystem() = default;

        static EventBuffer& Events();

        static void dispatchNewEvents();

    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
