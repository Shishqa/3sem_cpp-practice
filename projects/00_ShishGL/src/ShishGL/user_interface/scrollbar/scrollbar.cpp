/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(Window* parent, FrameScrollable* target,
                     const ScrollbarColorscheme& colors,
                     const Vector2<int>& pos,
                     const Vector2<size_t>& size)
        : RectWindow(parent, colors.bg, pos, size)
        , FrameScrollable()
        , target(target) {

    Vector2<size_t> button_size{size.x, size.x};
    auto slide_size = size - Vector2<size_t>{0, 2 * button_size.y};

    /*------------------------------------------------------------------------*/
    attach<ScrollButton>(
        -1.0,
        colors.button,
        Vector2<int>{0, 0},
        button_size
        );

    attach<ScrollButton>(
        +1.0,
        colors.button,
        Vector2<int>{0, static_cast<int>(button_size.y + slide_size.y)},
        button_size
        );
    /*------------------------------------------------------------------------*/

    double proportion = (target ? target->getProportion() : DEFAULT_PROPORTION);
    Vector2<size_t> slider_size{
        slide_size.x,
        static_cast<size_t>(proportion * static_cast<double>(slide_size.y))
        };

    Vector2<int> slider_guide{
        0, static_cast<int>(slide_size.y - slider_size.y)
    };

    slider = attach<ScrollSlider>(
            colors.slider,
            slider_guide,
            Vector2<int>{0, static_cast<int>(button_size.y)},
            slider_size
            );

}

/*----------------------------------------------------------------------------*/

double Scrollbar::contentProportion() {
    if (target) {
        return static_cast<double>(getFrameSize()) /
               static_cast<double>(target->getFrameSize());
    }
    return 1.0;
}

/*----------------------------------------------------------------------------*/

void Scrollbar::slide(int delta) {
    slider->slide(delta);
}

/*----------------------------------------------------------------------------*/

size_t Scrollbar::stepSize() {
    if (target) {
        return target->stepSize() * contentProportion();
    }
    return DEFAULT_STEP_SIZE;
}

/*----------------------------------------------------------------------------*/

size_t Scrollbar::getFrameSize() {
    return slider->getSize().y;
}

/*----------------------------------------------------------------------------*/

size_t Scrollbar::getContentSize() {
    return getSize().y - 2 * getSize().x;
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

    auto n_steps = static_cast<int>(event->delta());

    scroll(n_steps);

    if (target) {
        target->scroll(n_steps);
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool Scrollbar::unhandledEvent(const Event* event) {

    if (event->type() == Event::SLIDE) {

        auto converted = dynamic_cast<const SlideEvent*>(event);
        if (!converted) {
            return false;
        }

        if (target) {
            target->slide(static_cast<int>(converted->delta() / contentProportion()));
        }

        return true;
    }

    return false;
}

/*============================================================================*/
