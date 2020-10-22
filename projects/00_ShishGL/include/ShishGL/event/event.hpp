/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include <cstdint>

#include "ShishGL/utility/input.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window;

    /*------------------------------------------------------------------------*/

    class Event {
    public:
        virtual ~Event() = default;
    };

    /*------------------------------------------------------------------------*/

    class GlobalRenderEvent : public Event {
    public:
        ~GlobalRenderEvent() override = default;
    };

    /*------------------------------------------------------------------------*/

    class InputEvent : public Event {
    public:

        ~InputEvent() override = default;

        [[nodiscard]]
        const KbdModifiers& modifiers() const { return kbd_modifiers; }

    private:

        KbdModifiers kbd_modifiers;

    };

    /*------------------------------------------------------------------------*/

    class MouseEvent : public InputEvent {
    public:
        ~MouseEvent() override = default;

        [[nodiscard]]
        const Vector2<int>& where() const { return location; }

    private:
        Vector2<int> location;
    };

    /*------------------------------------------------------------------------*/

    class MouseMoveEvent : public MouseEvent {
    public:
        ~MouseMoveEvent() override = default;
    };

    /*------------------------------------------------------------------------*/

    class MouseClickEvent : public MouseEvent {
    public:
        ~MouseClickEvent() override = default;

        [[nodiscard]]
        const uint8_t& button() const { return button_id; }

        [[nodiscard]]
        const uint8_t& state() const { return button_state; }

    private:
        uint8_t button_id;
        uint8_t button_state;
    };

    /*------------------------------------------------------------------------*/

    class KeyboardEvent : public InputEvent {
    public:
        ~KeyboardEvent() override = default;

        [[nodiscard]]
        const uint8_t& key() const { return key_pressed; }

        [[nodiscard]]
        const uint8_t& state() const { return key_state; }

    private:
        uint8_t key_pressed;
        uint8_t key_state;
    };

    /*------------------------------------------------------------------------*/

    class WindowEvent : public Event {
    public:
        ~WindowEvent() override = default;

        [[nodiscard]]
        Window* const& target() const { return win_ptr; }

    private:
        Window* win_ptr;
    };

    /*------------------------------------------------------------------------*/

    class IdleEvent : public WindowEvent {
    public:
        ~IdleEvent() override = default;
    };

    /*------------------------------------------------------------------------*/

    class RenderEvent : public WindowEvent {
    public:
        ~RenderEvent() override = default;
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
