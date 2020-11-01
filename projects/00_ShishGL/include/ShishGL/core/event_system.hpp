/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include <type_traits>
#include <queue>
#include <cstdio>

#include "object/object.hpp"
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    public:

        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static void postEvent(Args&&... args) {

            /* TODO: check inheritance relations */

            auto event = new SomeEvent(std::forward<Args>(args)...);
            Events().push(event);
        }
        /*--------------------------------------------------------------------*/
        template <typename SomeEvent, typename... Args>
        static bool sendEvent(Object* object, Args&&... args) {

            auto event = new SomeEvent(std::forward<Args>(args)...);

            bool status = sendEvent(object, event);

            delete event;
            return status;
        }
        /*--------------------------------------------------------------------*/
        static bool sendEvent(Object* object, const Event* event);
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
