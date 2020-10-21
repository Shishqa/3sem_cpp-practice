/*============================================================================*/

#include <cstdio>
#include <stdexcept>

#include "vector2.hpp"
#include "window_manager.hpp"
#include "log.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

Window::Window(const Vector2<size_t>& size,
               const Vector2<int>& pos,
               const std::string_view& win_title)
        : info({win_title, EngiID_UNDEFINED, pos, size}) {
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
}

/*----------------------------------------------------------------------------*/

//TODO: set window before redrawing
void Window::refresh() {
    this->onRender();
}

/*============================================================================*/
