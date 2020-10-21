/*============================================================================*/
#ifndef EVENT_HPP
#define EVENT_HPP
/*============================================================================*/

#include <queue>

#include "ShishGL/engines/graphic_interface.hpp"

/*============================================================================*/

namespace ShishGL {

    using KeyboardModifiers = uint8_t;

    /* TODO: arrange values */
    constexpr KeyboardModifiers KB_LSHIFT = 0b00000000,
                                KB_RSHIFT = 0b00000000,
                                KB_LCTRL  = 0b00000000,
                                KB_RCTRL  = 0b00000000,
                                KB_LALT   = 0b00000000,
                                KB_RALT   = 0b00000000,
                                KB_META   = 0b00000000;

    /*------------------------------------------------------------------------*/

    class Event {
    public:

        virtual ~Event() = default;

    };

    /*------------------------------------------------------------------------*/

    class RenderEvent : public Event {
    public:

        ~RenderEvent() override = default;
    };

    /*------------------------------------------------------------------------*/

    class IdleEvent : public Event {
    public:

        ~IdleEvent() override = default;
    };

    /*------------------------------------------------------------------------*/

    class InputEvent : public Event {
    public:


        KeyboardModifiers modifiers();

    private:

        KeyboardModifiers kb_modifiers;

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
