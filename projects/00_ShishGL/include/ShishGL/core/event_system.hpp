/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include <type_traits>
#include <queue>
#include <cstdio>

#include "object/object_manager.hpp"
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    private:

        template <typename SomeEvent, typename T>
        using Helper =
                std::enable_if_t<std::is_base_of<Event, SomeEvent>::value, T>;

    public:

        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static Helper<SomeEvent, void> postEvent(Args&&... args) {

            auto event = new SomeEvent(std::forward<Args>(args)...);
            Events().push(event);
        }
        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static Helper<SomeEvent, bool>
        sendEvent(Object::ID receiver, Args&&... args) {

            auto event = new SomeEvent(std::forward<Args>(args)...);

            bool status = sendEvent(receiver, event);

            delete event;
            return status;
        }
        /*--------------------------------------------------------------------*/
        static bool sendEvent(Object::ID receiver, const Event* event);
        /*--------------------------------------------------------------------*/

        virtual ~EventSystem() = default;

    private:

        EventSystem() = default;

        /*--------------------------------------------------------------------*/
        friend class CoreApplication;
        /*--------------------------------------------------------------------*/

        static bool pollEngine();

        static void dispatchEvents();

        static void dispatchSingleEvent();

        static void flush();

        /*--------------------------------------------------------------------*/

        using EventQueue = std::queue<const Event*>;

        static EventQueue& Events();

        /*--------------------------------------------------------------------*/

        static Timer& EventTimer();

    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_BUFFER_HPP
/*============================================================================*/
