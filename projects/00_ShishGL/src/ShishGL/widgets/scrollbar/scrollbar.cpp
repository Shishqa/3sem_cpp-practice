/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/widgets/scrollbar/scrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(Window* parent, const ScrollbarColorscheme& colors,
                     const Vector2<int>& pos,
                     const Vector2<size_t>& size)
        : RectWindow(parent, colors.bg, pos, size) {

    slider = attach<ScrollbarSlider>(
            colors.slider,
            Vector2<int>{0, static_cast<int>(size.y - 50)},
            Vector2<int>{0, 0},
            Vector2<size_t>{size.x, 50}
            );
}

/*----------------------------------------------------------------------------*/

bool Scrollbar::filterEvent(const Event* event) {

    if (event->type() == Event::MOUSE_SCROLL) {

        auto mouse = dynamic_cast<const MouseEvent*>(event);
        if (!mouse) {
            return false;
        }

        if (!RectWindow::contains(mouse->where())) {
            return false;
        }

        return true;
    }

    return RectWindow::filterEvent(event);
}

/*----------------------------------------------------------------------------*/

bool Scrollbar::onMouseScroll(const MouseScrollEvent *event) {
    double ratio = -1.0 * event->delta() / 10.0;
    slider->advance(ratio);
    return true;
}

/*============================================================================*/
