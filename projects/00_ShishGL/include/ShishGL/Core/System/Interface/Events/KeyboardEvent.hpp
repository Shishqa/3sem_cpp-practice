/*============================================================================*/
#ifndef SHISHGL_KEYBOARD_EVENT_HPP
#define SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
#include "Event.hpp"
#include "Keyboard.hpp"
#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class KeyboardEvent : public Event {
    public:

        KeyboardEvent(Keyboard::Key key,
                      Keyboard::KeyState state,
                      Keyboard::ModifierMask modifiers);

        ~KeyboardEvent() override = default;

        [[nodiscard]]
        inline Keyboard::Key key() const;

        [[nodiscard]]
        inline Keyboard::KeyState state() const;

        [[nodiscard]]
        inline Keyboard::ModifierMask modifiers() const;

        bool happen(Object::ID listener) override;

    protected:

        Keyboard::Key k_key;
        Keyboard::KeyState k_state;
        Keyboard::ModifierMask k_modifiers;

    };

}
/*============================================================================*/
#endif //SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
