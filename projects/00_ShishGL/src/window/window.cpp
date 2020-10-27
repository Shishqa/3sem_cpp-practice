/*============================================================================*/
#include "ShishGL/window/window.hpp"
#include "ShishGL/geometry/vector2.hpp"
#include "ShishGL/log.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(const Vector2<size_t>& size,
               const Vector2<int>& pos)
               : info({pos, size}) {

    LogSystem::printLog("Created window %p at (%d, %d) %lux%lupx",
                        reinterpret_cast<void*>(this),
                        pos.x, pos.y,
                        size.x, size.y);
}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    LogSystem::printLog("Window %p destroyed",
                        reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

const Window::WindowInfo& Window::getInfo() const {
    return info;
}

/*----------------------------------------------------------------------------*/

void Window::display() const {
}

/*----------------------------------------------------------------------------*/

void Window::close() const {
}

/*----------------------------------------------------------------------------*/

//TODO: set window before redrawing
void Window::refresh() {
}

/*----------------------------------------------------------------------------*/

/* TODO: */
bool Window::getEvent(const Event* event) {
    return false;
}

/*============================================================================*/
