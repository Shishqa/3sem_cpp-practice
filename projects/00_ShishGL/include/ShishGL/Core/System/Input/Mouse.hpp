/*============================================================================*/
#ifndef SHISHGL_MOUSE_HPP
#define SHISHGL_MOUSE_HPP
/*============================================================================*/
#include "../../Primitives/Vector2.hpp"
#include "../engine/engine.hpp"
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

        static inline Vector2<double> getPosition();

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_HPP
/*============================================================================*/