/*============================================================================*/
#ifndef SHISHGL_MOUSE_HPP
#define SHISHGL_MOUSE_HPP
/*============================================================================*/
#include "ShishGL/geometry/vector2.hpp"
#include "ShishGL/core/engine/engine.hpp"
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

        static inline Vector2<int> getPosition() {
            return Engine::getMousePos();
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_HPP
/*============================================================================*/