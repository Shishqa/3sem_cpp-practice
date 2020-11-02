/*============================================================================*/
#include "ShishGL/graphics/window/window.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event/base_event.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::~Window() {
    delete shape;
}

/*----------------------------------------------------------------------------*/

Vector2<double> Window::getAbsPos() const {
    return shape->getPos();
}

/*----------------------------------------------------------------------------*/

bool Window::contains(const Vector2<double>& point) const {
    return shape->contains(point);
}

/*----------------------------------------------------------------------------*/

bool Window::onRender() {
    shape->draw();
    return true;
}

/*----------------------------------------------------------------------------*/

bool Window::onMouseMove(const MouseEvent* event) {

    const bool is_event_inside = contains(event->where());

    if (is_event_inside && !is_mouse_inside) {

        is_mouse_inside = true;
        onMouseEnter(event);
        return true;

    } else if (!is_event_inside && is_mouse_inside) {

        is_mouse_inside = false;
        onMouseLeave(event);
        return true;

    }

    return Object::onMouseMove(event);
}

/*============================================================================*/
