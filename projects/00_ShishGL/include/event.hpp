/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/

#include <cstdint>

#include "vector2.hpp"

/*============================================================================*/

namespace ShishGL {

    using KeyboardModifiers = uint8_t;

    /* TODO: finish this up */
    constexpr KeyboardModifiers KB_L_SHIFT = 0b00000000;

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

        ~InputEvent() override = default;

    private:

        KeyboardModifiers kb_modifiers;

    };

    /*------------------------------------------------------------------------*/

    class MouseEvent : public InputEvent {
    public:
        ~MouseEvent() override = default;

    private:
        Vector2<int> where;
        uint8_t button;
        uint8_t state;
    };

    /*------------------------------------------------------------------------*/

    class KeyboardEvent : public InputEvent {
    public:
        ~KeyboardEvent() override = default;

    private:
        uint8_t key;
        uint8_t state;
    };

}

/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
