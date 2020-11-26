/*============================================================================*/
#include "Window.hpp"
#include "WindowManager.hpp"
#include "LogSystem.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(const Viewport& frame)
        : frame(frame)
        , view(frame)
        , parent(WindowManager::ROOT) {
    fitParent();
}

/*----------------------------------------------------------------------------*/

const Window* Window::getParent() const {
    return parent;
}

const Viewport& Window::getFrame() const {
    return frame;
}

/*============================================================================*/

void Window::setParent(Window* new_parent) {
    parent = new_parent;
    if (parent) {
        translate(parent->getPos());
    }
    fitParent();
}

/*----------------------------------------------------------------------------*/

void Window::attach(Window* child) {
    children.insert(child);
    child->setParent(this);
}

/*----------------------------------------------------------------------------*/

void Window::detach(Window* child) {
    children.erase(child);
}

/*============================================================================*/

void Window::render() {
    onRender();
    for (auto& child : children) {
        child->render();
    }
}

/*----------------------------------------------------------------------------*/

void Window::onRender() {
    RENDERER().setViewport(frame.pos, frame.size);
}

/*============================================================================*/

void Window::fitParent() {
    if (parent) {
        view.fit_into(parent->view);
        for (auto& child : children) {
            child->fitParent();
        }
    }
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Window::getPos() const {
    return frame.pos;
}

/*----------------------------------------------------------------------------*/

void Window::setPos(const Vector2<double>& pos) {

    Vector2<double> old_pos = pos;

    frame.pos = pos;
    fitParent();

    for (auto& child : children) {
        child->translate(pos - old_pos);
    }
}

/*----------------------------------------------------------------------------*/

void Window::translate(const Vector2<double>& delta) {

    frame.pos += delta;
    fitParent();

    for (auto& child : children) {
        child->translate(delta);
    }
}

/*----------------------------------------------------------------------------*/

bool Window::contains(const Vector2<double>& point) const {
    return (frame.pos.x <= point.x && point.x <= frame.pos.x + frame.size.x &&
            frame.pos.y <= point.y && point.y <= frame.pos.y + frame.size.y);
}

/*============================================================================*/