/*============================================================================*/
#include "Window.hpp"
#include "WindowManager.hpp"
#include "LogSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(const Viewport& win_vp)
    : is_active(false)
    , viewport(win_vp) {
    fit_parent();
}

/*----------------------------------------------------------------------------*/

void Window::onRender() { /* something */ }

/*============================================================================*/

bool Window::onMouseEntered(MouseEvent&) { return false; }

bool Window::onMouseLeft(MouseEvent&) { return false; }

/*----------------------------------------------------------------------------*/

bool Window::onMouseMove(MouseEvent& event) {

    bool is_event_inside = contains(event.where());

    bool status = false;

    if (is_active && !is_event_inside) {

        is_active = false;

        if (onMouseLeft(event)) {
            status = true;
        }

    } else if (!is_active && is_event_inside) {

        is_active = true;
        if (onMouseEntered(event)) {
            status = true;
        }
    }

    if (EventSystem::sendEvent(this, event))
    {
        status = true;
    }

    return status;
}

/*----------------------------------------------------------------------------*/

const Viewport& Window::getViewport() const {
    return viewport;
}

/*----------------------------------------------------------------------------*/

void Window::fit_parent() {

    auto& node = WindowManager::get(this);

    node.to_set = viewport;

    if (node.parent) {
        node.to_set.fit_into(node.parent->getViewport());
    }
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Window::getPos() const {
    return viewport.pos;
}

/*----------------------------------------------------------------------------*/

void Window::setPos(const Vector2<double>& pos) {
    viewport.pos = pos;
    fit_parent();
}

/*----------------------------------------------------------------------------*/

void Window::translate(const Vector2<double>& delta) {
    viewport.pos += delta;
    fit_parent();
}

/*----------------------------------------------------------------------------*/

bool Window::contains(const Vector2<double>& point) const {
    return (viewport.pos.x <= point.x && point.x <= viewport.pos.x + viewport.size.x &&
            viewport.pos.y <= point.y && point.y <= viewport.pos.y + viewport.size.y);
}

/*============================================================================*/