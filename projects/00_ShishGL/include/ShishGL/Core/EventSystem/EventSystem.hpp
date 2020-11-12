/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include "EventManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventSystem {
    public:

        static constexpr Object::ID SystemEvents = 1;

        template <typename SomeEvent, typename... Args>
        static bool sendEvent(Object::ID sender, Args&&... args);

        static bool sendEvent(Object::ID sender, Event* event);

        static bool dispatchAll();

        static bool dispatchOne();

        virtual ~EventSystem() = default;

    protected:

        EventSystem() = default;

    };

}
/*============================================================================*/
#include "EventSystem.ipp"
/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
