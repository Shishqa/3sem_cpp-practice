/*============================================================================*/
#ifndef SHISHGL_MOUSE_HPP
#define SHISHGL_MOUSE_HPP
/*============================================================================*/
namespace ShishGL {

    class Mouse {
    public:

        enum ButtonState {
            DOWN,
            UP
        };

        enum Button {
            LEFT,
            RIGHT,
            MIDDLE
        };

        using ScrollDelta = double;

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_HPP
/*============================================================================*/