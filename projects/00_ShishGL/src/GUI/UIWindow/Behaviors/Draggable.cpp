/*============================================================================*/
#include "Draggable.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Draggable::Draggable(UIWindow* target)
    : Holdable(target)
    , drag_point({})
    { }

const Vector2<double>& Draggable::dragPoint() const {
    return drag_point;
}

/*----------------------------------------------------------------------------*/

bool Draggable::onMouseButton(MouseButtonEvent& event) {

    Holdable::onMouseButton(event);

    if (Mouse::DOWN == event.state() &&
        1 == numHeld()) {
        drag_point = event.where();
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool Draggable::onMouseMove(MouseEvent& event) {

    Holdable::onMouseMove(event);

    if (isHeld()) {
        target<UIWindow>()->translate(event.where() - drag_point);
        drag_point = event.where();
    }

    return true;
}

/*============================================================================*/