/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollButton::ScrollButton(Window *parent, Mouse::ScrollDelta delta,
                           const ButtonColorScheme &colors,
                           const Vector2<int> &pos,
                           const Vector2<size_t> &size)
    : RectButton(parent, colors, pos, size)
    , delta(delta) {}

/*----------------------------------------------------------------------------*/

void ScrollButton::reactOnButton(const MouseButtonEvent* event) {
    if (event->state() == Mouse::DOWN) {
        EventSystem::sendEvent<MouseScrollEvent>(
                parent,
                Event::MOUSE_SCROLL,
                getAbsPos(),
                delta
                );
    }
}

/*============================================================================*/
