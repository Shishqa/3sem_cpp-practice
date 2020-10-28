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
        static void postEvent(Event::EventType type) {

            auto event = new Event{type, {}};
            Events().push(event);
        }
        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static bool sendEvent(Object* object, Event::EventType type, Args&&... args) {

            auto event = new Event{
                type,
                SomeEvent{std::forward<Args>(args)...}
            };

            bool status = send(object, event);

            delete event;
            return status;
        }
        /*--------------------------------------------------------------------*/
        static bool sendEvent(Object* object, Event::EventType type) {

            auto event = new Event{type, { }};

            bool status = send(object, event);

            delete event;
            return status;
        }
        /*--------------------------------------------------------------------*/

        virtual ~EventSystem() = default;

    private:

        static bool send(Object* object, const Event* event);

        EventSystem() = default;

        /*--------------------------------------------------------------------*/
        friend class CoreApplication;
        /*--------------------------------------------------------------------*/

        static void pollEngine();

        static void dispatchEvents();

        static void dispatchSingleEvent();

        static void flush();

        /*--------------------------------------------------------------------*/

        using EventQueue = std::queue<const Event*>;

        static EventQueue& Events();
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_BUFFER_HPP
/*============================================================================*/
