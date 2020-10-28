/*============================================================================*/
#ifndef INC_00_SHISHGL_INPUT_HPP
#define INC_00_SHISHGL_INPUT_HPP
/*============================================================================*/
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Mouse {
    public:

        enum State {
            DOWN,
            UP
        };

        enum Button {
            LEFT,
            RIGHT,
            MIDDLE
        };

        enum Wheel {
            SCROLL_UP,
            SCROLL_DOWN
        };

        enum CursorState {
            IN,
            OUT
        };

    };

    class Keyboard {
    public:

        using Key = uint8_t;

        using Modifier = uint8_t;

        static constexpr Modifier L_SHIFT   = 0b00000001,
                                  R_SHIFT   = 0b00010000,
                                  L_CTRL    = 0b00000010,
                                  R_CTRL    = 0b00100000,
                                  L_ALT     = 0b00000100,
                                  R_ALT     = 0b01000000,
                                  META      = 0b10000000,
                                  CAPS_LOCK = 0b00001000;

        enum State {
            UP,
            DOWN
        };

    };

}
/*============================================================================*/
#endif //INC_00_SHISHGL_INPUT_HPP
/*============================================================================*/
