/*============================================================================*/
#include "LogSystem.hpp"
#include "EventManager.hpp"
#include "UIScrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(UIWindow* target, const double& slider_ratio,
                     Scrollbar::Type type)
        : Clickable(target)
        , inc_button(nullptr)
        , dec_button(nullptr)
        , slider(nullptr) {

    Vector2<double> size = target->getFrame().size;
    Vector2<double> button_size = {};

    if (type == VERTICAL) {

        button_size = {size.x, size.x};

        inc_button = target->attach<UIWindow>(
                Viewport{ {0, 0}, button_size }
                );

        dec_button = target->attach<UIWindow>(
                Viewport{ {0, size.y - button_size.y}, button_size }
                );

        slider = target->attach<UIWindow>(
                Viewport{ {0, button_size.y * 2}, button_size }
                );

    } else {

        button_size = {size.y, size.y};

        inc_button = target->attach<UIWindow>(
                Viewport{ {0, 0}, button_size }
                );

        dec_button = target->attach<UIWindow>(
                Viewport{ {size.x - button_size.x, 0}, button_size }
                );

        slider = target->attach<UIWindow>(
                Viewport{ {button_size.x * 2, 0}, button_size }
                );

    }

    /*
    Vector2<double> button_size{size.x, size.x};
    auto slide_space_size = size - Vector2<double>{0, 2 * button_size.y};

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

    double slider_height = MIN_SLIDER_SIZE;
    if (target) {
        slider_height = std::max(
                slider_height,
                slide_space_size.y * target->frameSize() / target->limitSize()
                );
    }

    Vector2<double> slider_size{slide_space_size.x, slider_height};
    Vector2<double> slider_guide{0, slide_space_size.y - slider_size.y};
    Vector2<double> slider_pos{0, button_size.y};

    slider = attach<ScrollSlider>(
            colors.slider,
            slider_guide,
            slider_size,
            slider_pos
    );
    */

}

/*----------------------------------------------------------------------------*/

void Scrollbar::reactOnPress(MouseButtonEvent&) {

    printf("PRESSED!\n");

    /*
    if (ObjectManager::get<ScrollSlider>(slider).contains(event->where()) ||
        ObjectManager::get<ScrollButton>(up_button).contains(event->where()) ||
        ObjectManager::get<ScrollButton>(down_button).contains(event->where())) {
        return;
    }

    if (event->state() == Mouse::DOWN) {
        EventSystem::sendEvent<MouseButtonEvent>(slider, Event::MOUSE_BUTTON,
                                                 ObjectManager::get<ScrollSlider>(slider).getCenter(),
                                                 Mouse::LEFT, Mouse::DOWN);

        EventSystem::sendEvent<MouseEvent>(slider, Event::MOUSE_MOVE,
                                           event->where());
    }

    */
}

/*
ScrollSlider::ScrollSlider(Object::ID id, Object::ID parent, const ButtonColorScheme &colors,
                           const Vector2<double>& guide,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectSlider(id, parent, colors, guide, size, pos) {}


bool ScrollSlider::onMouseMove(const MouseEvent* event) {

    auto old_pos = where_dragged;

    if (!RectSlider::onMouseMove(event)) {
        return false;
    }

    auto new_pos = where_dragged;

    EventSystem::sendEvent<SlideEvent>(
            parent,
            Event::SLIDE,
            (new_pos - old_pos) ^ (!guide)
    );

    return true;
}
ScrollButton::ScrollButton(Object::ID id, Object::ID parent,
                           Mouse::ScrollDelta delta,
                           const ButtonColorScheme& colors,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectHoldableButton(id, parent, colors, size, pos)
        , delta(delta) {}


void ScrollButton::reactOnHold(TimerEvent&) {
    EventSystem::sendEvent<MouseScrollEvent>(
            id(),
            getAbsPos(),
            delta
    );
}
*/

/*============================================================================*/
