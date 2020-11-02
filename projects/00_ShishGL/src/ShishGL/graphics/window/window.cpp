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
    for (const auto& sub_win : subwindows) {
        delete sub_win;
    }
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Window::getAbsPos() const {
    return shape->getPos();
}

/*----------------------------------------------------------------------------*/

Vector2<double> Window::getRelPos() const {
    if (parent) {
        return getAbsPos() - parent->getAbsPos();
    }
    return getAbsPos();
}

/*----------------------------------------------------------------------------*/

void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

Window* Window::detach(Window* win_ptr) {
    return (subwindows.erase(win_ptr) ? win_ptr : nullptr);
}

/*----------------------------------------------------------------------------*/

bool Window::onRender() {
    shape->render();
}

/*----------------------------------------------------------------------------*/

bool Window::onMouseMove(const MouseEvent* event) {

    const bool is_event_inside = shape->contains(event->where());

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
