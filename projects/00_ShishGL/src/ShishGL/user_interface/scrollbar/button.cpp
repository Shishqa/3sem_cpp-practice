/*============================================================================*/
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollButton::ScrollButton(Object::ID id, Object::ID parent,
                           Mouse::ScrollDelta delta,
                           const ButtonColorScheme& colors,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
    : RectHoldableButton(id, parent, colors, size, pos)
    , delta(delta) {}

/*----------------------------------------------------------------------------*/

void ScrollButton::reactOnHold(TimerEvent&) {
    EventSystem::sendEvent<MouseScrollEvent>(
            id(),
            getAbsPos(),
            delta
            );
}

/*============================================================================*/
