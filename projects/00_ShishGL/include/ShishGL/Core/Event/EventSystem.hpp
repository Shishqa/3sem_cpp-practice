/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include <type_traits>
#include <queue>

#include "Event.hpp"
#include "Object.hpp"
#include "Time.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    private:

        template <typename SomeEvent, typename T>
        using Helper =
                std::enable_if_t<std::is_base_of<Event, SomeEvent>::value, T>;

    public:

        static constexpr Object::ID SYSTEM_EVENTS = 1;

        template <typename SomeEvent, typename... Args>
        static Helper<SomeEvent, void> postEvent(Args&&... args);

        template <typename SomeEvent, typename... Args>
        static Helper<SomeEvent, bool> sendEvent(Object::ID sender, Args&&... args);

        static bool sendEvent(Object::ID sender, Event* event);

        virtual ~EventSystem() = default;

    private:

        EventSystem() = default;

        /*--------------------------------------------------------------------*/
        friend class CoreApplication;
        /*--------------------------------------------------------------------*/

        static void dispatchEvents();

        static void dispatchSingleEvent();

        static void flush();

        /*--------------------------------------------------------------------*/

        using EventQueue = std::queue<Event*>;

        static EventQueue& Events();

        /*--------------------------------------------------------------------*/

        static Timer& EventTimer();

    };

}
/*============================================================================*/
#include "EventSystem.ipp"
/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
