/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include <type_traits>
#include <queue>
#include <cstdio>

#include "object.hpp"
#include "event.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    public:

        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static void postEvent(Event::EventType type, Args&&... args) {

            /* TODO: check inheritance relations */

            auto event = new Event{
                type,
                SomeEvent{std::forward<Args>(args)...}
            };

            Events().push(event);
        }
        /*--------------------------------------------------------------------*/
        template <typename... Args>
        static void postEvent(Args&&... args) {

            auto event = new Event{std::forward<Args>(args)...};

            Events().push(event);
        }
        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static bool sendEvent(Object* object, Event::EventType type, Args&&... args) {

            /* TODO: check inheritance relations */

            auto event = new Event{
                type,
                SomeEvent{std::forward<Args>(args)...}
            };

            bool status = object->getEvent(event);

            delete event;
            return status;
        }

        /*--------------------------------------------------------------------*/

        virtual ~EventSystem() = default;

    private:

        EventSystem() = default;

        /*--------------------------------------------------------------------*/
        friend class CoreApplication;
        /*--------------------------------------------------------------------*/

        static void pollEngine();

        static bool dispatchEvents();

        static bool dispatchSingleEvent();

        /*--------------------------------------------------------------------*/

        using EventQueue = std::queue<const Event*>;

        static EventQueue& Events();
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_BUFFER_HPP
/*============================================================================*/
