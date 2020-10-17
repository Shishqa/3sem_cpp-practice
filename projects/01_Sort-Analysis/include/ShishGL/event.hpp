/*============================================================================*/
#ifndef EVENT_HPP
#define EVENT_HPP
/*============================================================================*/

#include <queue>
#include "graphic_interface.hpp"

/*============================================================================*/

namespace ShishGL {

    class Object;
    class Window;
    class WindowManager;

    /*------------------------------------------------------------------------*/

    class Event {
    public:

        Event() = default;

        virtual void operator()() = 0;

        virtual ~Event() = default;
    };

    /*------------------------------------------------------------------------*/

    class TargetedEvent : public Event {
    public:

        TargetedEvent() = delete;

        TargetedEvent(Object* target);

        virtual ~TargetedEvent() = default;

    private:
        Object* target;
    };

    /*------------------------------------------------------------------------*/

    class RenderEvent : public TargetedEvent {
    public:

        RenderEvent(Window* target);

        virtual ~RenderEvent() = default;
    };

    /*------------------------------------------------------------------------*/

    class IdleEvent : public TargetedEvent {
    public:
        virtual ~IdleEvent() = default;
    };

    /*------------------------------------------------------------------------*/

    class MouseEvent : public TargetedEvent {
    public:
        virtual ~MouseEvent() = default;

    private:
        int button;
        int state;
        int rel_x, rel_y;
    };

    /*------------------------------------------------------------------------*/

    class KeyboardEvent : public TargetedEvent {
    public:
        virtual ~KeyboardEvent() = default;

    private:
        uint8_t key;
        int state;
        uint8_t special_keys;
    };

    /*------------------------------------------------------------------------*/

    class EventSystem {
    public:

        ~EventSystem() = default;

        //static void sendSignal(const Signal* signal);

    private:

        EventSystem()  = default;

        using EventQueue = std::queue<const Event*>;

        static EventQueue& Events();

        static void processNewEvents();

        friend Object;
        friend WindowManager;
    };


    class EventBuffer {
    public:

        EventBuffer() = default;

        EventBuffer(const EventBuffer& other) = delete;

        EventBuffer& operator=(const EventBuffer& other) = delete;

        virtual ~EventBuffer();

        void addEvent(const Event* event_p) {
            events.push(event_p);
        }

        [[nodiscard]] const Event* nextEvent() {
            const Event* event_p = events.front();
            events.pop();
            return event_p;
        }

    private:

        using EventQueue = std::queue<const Event*>;

        EventQueue events;

    };


}

/*============================================================================*/
#endif //EVENT_HPP
/*============================================================================*/
