/*============================================================================*/
#include "Window.hpp"
#include "WindowManager.hpp"
#include "RectangleShape.hpp"
#include "LogSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void Window::applyShape(Shape2D* new_shape) {

    delete shape;
    shape = new_shape;

    viewport.fit(*shape);
    fit_parent();
}

/*----------------------------------------------------------------------------*/

Window::Window(Shape2D* win_shape)
    : is_active(false)
    , shape(nullptr)
    , viewport({}) {
    applyShape(win_shape);
}

/*----------------------------------------------------------------------------*/

Window::~Window() {

    for (auto style : styles) {
        delete style;
    }

    delete shape;
}

/*----------------------------------------------------------------------------*/

void Window::onRender() {

    for (auto style : styles) {
        style->apply(shape);
    }

    shape->draw();
}

/*============================================================================*/

bool Window::onMouseEntered(MouseEvent&) { return false; }

bool Window::onMouseLeft(MouseEvent&) { return false; }

/*----------------------------------------------------------------------------*/

bool Window::onMouseMove(MouseEvent& event) {

    bool is_event_inside = getShape().contains(event.where());

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

    if (resendMouse(event)) {
        status = true;
    }

    return status;
}

/*----------------------------------------------------------------------------*/

bool Window::onMouseButton(MouseButtonEvent& event) {
    return resendMouse(event);
}

/*----------------------------------------------------------------------------*/

bool Window::onMouseScroll(class MouseScrollEvent& event) {
    return resendMouse(event);
}

/*----------------------------------------------------------------------------*/

const Shape2D& Window::getShape() const {
    return *shape;
}

/*----------------------------------------------------------------------------*/

const Viewport& Window::getViewport() const {
    return viewport;
}

/*----------------------------------------------------------------------------*/

void Window::fit_parent() {
    Window *parent = WindowManager::getParent(this);
    if (parent) {
        viewport.fit_into(parent->getViewport());
    }
    viewport.recountDisplay();
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Window::getPos() const {
    return shape->getPos();
}

/*----------------------------------------------------------------------------*/

void Window::setPos(const Vector2<double>& pos) {

    shape->setPos(pos);

    viewport.fit(*shape);
    fit_parent();
}

/*----------------------------------------------------------------------------*/

void Window::translate(const Vector2<double>& delta) {

    shape->translate(delta);

    viewport.fit(*shape);
    fit_parent();
}

/*----------------------------------------------------------------------------*/

bool Window::contains(const Vector2<double>& point) {
    return shape->contains(point);
}

/*============================================================================*/