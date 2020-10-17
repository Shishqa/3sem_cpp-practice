/*============================================================================*/

#include <cstdio>
#include <stdexcept>

/*----------------------------------------------------------------------------*/

#include "ShishGL/window_manager.hpp"
#include "ShishGL/log.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

Window::Window(const Vector2<size_t>& size, const Vector2<int>& pos,
               const std::string_view& win_title)
        : info({win_title, ID_UNDEFINED, pos, size}) {
    printLog("Created window %p at (%d, %d) %lux%lupx",
             reinterpret_cast<void*>(this), pos.x, pos.y, size.x, size.y);
}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    printLog("Window %p destroyed",
             reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

const Window::WindowInfo& Window::getInfo() {
    return info;
}

/*----------------------------------------------------------------------------*/

void Window::display() {
    WindowManager::makeActive(this);
}

/*----------------------------------------------------------------------------*/

void Window::close() {
    WindowManager::makeInactive(this);
    printLog("%p win close", reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

//void Window::refresh() const {
//    glutSetWindow(info.id);
//    glutPostRedisplay();
//}

/*============================================================================*/
