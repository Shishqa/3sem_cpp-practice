/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/Core/Event/EventSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollSlider::ScrollSlider(Object::ID id, Object::ID parent, const ButtonColorScheme &colors,
                           const Vector2<double>& guide,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectSlider(id, parent, colors, guide, size, pos) {}

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