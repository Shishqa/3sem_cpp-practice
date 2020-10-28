/*============================================================================*/
#ifndef SHISHGL_BUTTON_HPP
#define SHISHGL_BUTTON_HPP
/*============================================================================*/
#include "../../core/window.hpp"
#include "ShishGL/utility/color.hpp"
#include "ShishGL/utility/color_collection.hpp"
/*============================================================================*/
namespace ShishGL {

    struct ButtonColors {
        Color normal;
        Color hover;
        Color click;
    };

    constexpr ButtonColors DEFAULT_BUTTON_COLORS = {
            SALMON, PEACH_PUFF, WHITE_SMOKE
    };

    class Button : public Window {
    public:

        Button(const Vector2<int>& pos)


    };

}
/*============================================================================*/
#endif //SHISHGL_BUTTON_HPP
/*============================================================================*/
