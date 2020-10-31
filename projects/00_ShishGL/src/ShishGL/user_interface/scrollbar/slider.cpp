/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollSlider::ScrollSlider(Window *parent, const ButtonColorScheme &colors,
                           const Vector2<int>& slide,
                           const Vector2<int>& pos,
                           const Vector2<size_t>& size)
        : RectSlider(parent, colors, slide, pos, size) {}

/*----------------------------------------------------------------------------*/

bool ScrollSlider::onMouseMove(const MouseEvent* event) {

    auto old_pos = static_cast<Vector2<double>>(getAbsPos());

    if (!RectSlider::onMouseMove(event)) {
        return false;
    }

    auto new_pos = static_cast<Vector2<double>>(getAbsPos());

    EventSystem::sendEvent<SlideEvent>(
            parent,
            Event::SLIDE,
            (new_pos - old_pos) ^ !guide
            );

    return true;
}

/*============================================================================*/