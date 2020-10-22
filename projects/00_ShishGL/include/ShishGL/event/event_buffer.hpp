/*============================================================================*/
#ifndef SHISHGL_EVENT_BUFFER_HPP
#define SHISHGL_EVENT_BUFFER_HPP
/*============================================================================*/
#include <queue>

#include "event.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventBuffer {
    public:

        template <typename SomeEvent, typename... Args>
        void postEvent(Args... args) {
            auto event = new SomeEvent(std::forward<Args>(args)...);
            events.push(event);
        }

        bool hasEvents() const;

        void flush();

        void dispatchNextEvent();

        /*--------------------------------------------------------------------*/

        EventBuffer() = default;

        EventBuffer(const EventBuffer& other) = delete;

        EventBuffer& operator=(const EventBuffer& other) = delete;

        virtual ~EventBuffer() = default;

    private:

        using EventQueue = std::queue<const Event*>;

        EventQueue events;
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_BUFFER_HPP
/*============================================================================*/
