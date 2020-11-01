/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event_system.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(Window* parent, FrameScrollable* target,
                     const ScrollbarColorscheme& colors,
                     const Vector2<double>& size,
                     const Vector2<double>& pos)
        : RectButton(parent, colors.bg, size, pos)
        , FrameScrollable()
        , target(target) {

    Vector2<double> button_size{size.x, size.x};
    auto slide_space_size = size - Vector2<double>{0, 2 * button_size.y};

    /*------------------------------------------------------------------------*/
    up_button = attach<ScrollButton>(
        -1.0,
        colors.button,
        button_size,
        Vector2<double>{0, 0}
        );

    down_button = attach<ScrollButton>(
        +1.0,
        colors.button,
        button_size,
        Vector2<double>{0, button_size.y + slide_space_size.y}
        );
    /*------------------------------------------------------------------------*/

    //double proportion = (target ? target->getProportion() : DEFAULT_PROPORTION);
    //static_cast<size_t>(proportion * static_cast<double>(slide_size.y))

    Vector2<double> slider_size{slide_space_size.x, MIN_SLIDER_SIZE};
    Vector2<double> slider_guide{0, slide_space_size.y - slider_size.y};
    Vector2<double> slider_pos{0, button_size.y};

    slider = attach<ScrollSlider>(
            colors.slider,
            slider_guide,
            slider_size,
            slider_pos
    );

}

/*----------------------------------------------------------------------------*/

double Scrollbar::contentProportion() {
    if (target) {
        return frameSize() / target->frameSize();
    }
    return 1.0;
}

/*----------------------------------------------------------------------------*/

void Scrollbar::slide(double delta_in_pixels) {
    slider->slide(delta_in_pixels);
}

/*----------------------------------------------------------------------------*/

double Scrollbar::stepSize() {
    if (target) {
        return target->stepSize() * contentProportion();
    }
    return DEFAULT_STEP_SIZE;
}

/*----------------------------------------------------------------------------*/

double Scrollbar::frameSize() {
    return slider->getGuide().length();
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

    return RectButton::filterEvent(event);
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
            target->slide(converted->delta() / contentProportion());
        }

        return true;
    }

    return false;
}

/*----------------------------------------------------------------------------*/

void Scrollbar::reactOnButton(const MouseButtonEvent* event) {

    if (slider->contains(event->where()) ||
        up_button->contains(event->where()) ||
        down_button->contains(event->where())) {
        return;
    }

    if (event->state() == Mouse::DOWN) {
        EventSystem::sendEvent<MouseButtonEvent>(slider, Event::MOUSE_BUTTON,
                                                 slider->getAbsPos(),
                                                 Mouse::LEFT, Mouse::DOWN);

        EventSystem::sendEvent<MouseEvent>(slider, Event::MOUSE_MOVE,
                                           event->where() - Vector2<double>{0, slider->getSize().y / 2});
    }
}

/*============================================================================*/
