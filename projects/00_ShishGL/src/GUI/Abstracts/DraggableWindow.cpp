/*============================================================================*/
#include "DraggableWindow.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

DraggableWindow::DraggableWindow(Shape2D* shape)
    : HoldableWindow(shape)
    , drag_point({0, 0})
    { }

/*------------------------------------------------------------------------*/

bool DraggableWindow::onMouseButton(MouseButtonEvent& event) {

    HoldableWindow::onMouseButton(event);

    if (Mouse::DOWN == event.state() &&
        1 == HoldableWindow::numHeld()) {
        drag_point = event.where();
    }

    return true;
}

/*------------------------------------------------------------------------*/

bool DraggableWindow::onMouseMove(MouseEvent& event) {

    HoldableWindow::onMouseMove(event);

    if (HoldableWindow::isHeld()) {
        translate(event.where() - drag_point);
        drag_point = event.where();
    }

    return true;
}

/*------------------------------------------------------------------------*/

const Vector2<double>& DraggableWindow::dragPoint() const {
    return drag_point;
}

/*============================================================================*/
