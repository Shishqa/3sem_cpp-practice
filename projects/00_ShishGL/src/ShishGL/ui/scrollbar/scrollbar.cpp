/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/ui/scrollbar/scrollbar.hpp"
#include "ShishGL/ui/scrollbar/slider.hpp"
#include "ShishGL/ui/scrollbar/scroll_buttons.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(Window* parent, const ScrollbarColorscheme& colors,
                     const Vector2<int>& pos,
                     const Vector2<size_t>& size)
        : RectWindow(parent, colors.bg, pos, size) {

    slider = attach<ScrollbarSlider>(
            colors.slider,
            Vector2<int>{0, static_cast<int>(size.y)},
            Vector2<int>{0, 0},
            Vector2<size_t>{size.x, 50}
            );

}

/*----------------------------------------------------------------------------*/

void Scrollbar::onMouseScroll(const Event *event) {
    double ratio = -1.0 * event->mouse_wheel.delta / 100.0;
    slider->advance(ratio);
}

/*============================================================================*/
