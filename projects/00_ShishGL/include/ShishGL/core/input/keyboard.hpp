/*============================================================================*/
#ifndef SHISHGL_KEYBOARD_HPP
#define SHISHGL_KEYBOARD_HPP
/*============================================================================*/
namespace ShishGL {

    class Keyboard {
    public:

        enum KeyState {
            DOWN,
            UP
        };

        using ModifierMask = uint8_t;

        static constexpr ModifierMask
            L_SHIFT_MOD   = 0b00000001,
            R_SHIFT_MOD   = 0b00010000,
            L_CTRL_MOD    = 0b00000010,
            R_CTRL_MOD    = 0b00100000,
            L_ALT_MOD     = 0b00000100,
            R_ALT_MOD     = 0b01000000,
            META_MOD      = 0b10000000;

        enum Key {
            UNKNOWN = -1,

            /* convertible: */
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Num0,
            Num1,
            Num2,
            Num3,
            Num4,
            Num5,
            Num6,
            Num7,
            Num8,
            Num9,
            SPACE,
            RETURN,
            COMMA,
            DOT,

            LAST_CONVERTIBLE,

            /* non-convertible: */
            BACKSPACE,
            DEL,
            ESC,
            TAB,
            CAPS_LOCK,
            L_SHIFT,
            R_SHIFT,
            L_CTRL,
            R_CTRL,
            META,
            L_ALT,
            R_ALT,
            ARROW_UP,
            ARROW_DOWN,
            ARROW_LEFT,
            ARROW_RIGHT,

            /* TODO: handle more */

            KEY_COUNT
        };

        [[nodiscard]]
        static inline bool isConvertible(Keyboard::Key key) {
            return (Key::UNKNOWN < key && key < Key::LAST_CONVERTIBLE);
        }

        [[nodiscard]]
        static uint8_t convertToChar(Keyboard::Key key) {

            if (!isConvertible(key)) {
                return 0;
            }

            if (key <= Keyboard::Key::Z) {
                return static_cast<uint8_t>(key) + 'A';
            }

            switch (key) {

                case Key::SPACE:  return (' ');
                case Key::RETURN: return ('\n');
                case Key::COMMA:  return (',');
                case Key::DOT:    return ('.');

                default: return 0;

            }
        }
    };

}
/*============================================================================*/
#endif //SHISHGL_KEYBOARD_HPP
/*============================================================================*/
