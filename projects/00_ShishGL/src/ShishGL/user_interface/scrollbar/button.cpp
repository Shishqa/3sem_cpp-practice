/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollButton::ScrollButton(Window *parent, Mouse::ScrollDelta delta,
                           const ButtonColorScheme& colors,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
    : RectHoldableButton(parent, colors, size, pos)
    , delta(delta) {}

/*----------------------------------------------------------------------------*/

void ScrollButton::reactOnHold(const TimerEvent*) {
    EventSystem::sendEvent<MouseScrollEvent>(
            parent,
            Event::MOUSE_SCROLL,
            getAbsPos(),
            delta
            );
}

/*============================================================================*/
