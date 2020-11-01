/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollSlider::ScrollSlider(Window *parent, const ButtonColorScheme &colors,
                           const Vector2<double>& guide,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectSlider(parent, colors, guide, size, pos) {}

/*----------------------------------------------------------------------------*/

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

/*============================================================================*/