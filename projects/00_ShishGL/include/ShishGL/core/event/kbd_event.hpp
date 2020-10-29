/*============================================================================*/
#ifndef SHISHGL_KEYBOARD_EVENT_HPP
#define SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
#include "base_event.hpp"
#include "ShishGL/core/input/keyboard.hpp"
/*============================================================================*/
namespace ShishGL {

    class KeyboardEvent : public Event {
    public:

        KeyboardEvent(Event::Type type, Keyboard::Key key,
                      Keyboard::KeyState state,
                      Keyboard::ModifierMask modifiers)
            : Event(type)
            , k_key(key)
            , k_state(state)
            , k_modifiers(modifiers) {}

        ~KeyboardEvent() override = default;

        [[nodiscard]]
        inline Keyboard::Key key() const { return k_key; }

        [[nodiscard]]
        inline Keyboard::KeyState state() const { return k_state; }

        [[nodiscard]]
        inline Keyboard::ModifierMask modifiers() const { return k_modifiers; }

    protected:

        Keyboard::Key k_key;
        Keyboard::KeyState k_state;
        Keyboard::ModifierMask k_modifiers;

    };

}
/*============================================================================*/
#endif //SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
