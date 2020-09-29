#include <cstdio>
#include <stdexcept>

#include <GL/freeglut.h>

#include "ShishGL/window.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


Window::Window(const Vector2<int>& position,
               const Vector2<size_t>& size)
        : info({WindowManager::WIN_ID_UNDEFINED, position, size}) {
    printLog("Created window %p at (%d, %d) %lux%lupx (but not initialised with GLUT)",
             reinterpret_cast<void*>(this), position.x, position.y, size.x, size.y);
}


Window::~Window() {

    for (auto& win : subwindows) {
        delete win;
    }

    printLog("Destroyed window %d", info.id);
}


//Window::Window(const Window& other)
//        : info(other.info) {
//    for (const auto& subwindow : other.subwindows) {
//        auto win_copy = new Window(*subwindow);
//        subwindows.emplace_back(win_copy);
//    }
//}
//
//
//Window& Window::operator=(const Window& other) {
//    if (&other == this) {
//        return *this;
//    }
//
//    info = other.info;
//    for (const auto& subwindow : other.subwindows) {
//        auto win_copy = new Window(*subwindow);
//        subwindows.emplace_back(win_copy);
//    }
//
//    return *this;
//}
//
//
//Window::Window(Window&& other) noexcept
//        : info(other.info), subwindows(other.subwindows) {}
//
//
//Window& Window::operator=(Window&& other) noexcept {
//    info = other.info;
//    subwindows = std::move(other.subwindows);
//
//    return *this;
//}


void Window::dump() {

    printf("{ %d ", info.id);

    for (auto& window : subwindows) {
        window->dump();
    }

    printf("}");
}


const Window::WindowInfo& Window::getInfo() {
    return info;
}


void Window::attach(Window* window) {

    subwindows.emplace_back(window);

    if (info.id == WindowManager::WIN_ID_UNDEFINED) {
        printLog("Warning: attached subwindow to not-initialized window!");
        return;
    }

    window->info.id = glutCreateSubWindow(info.id,
                                          window->info.pos.x, window->info.pos.y,
                                          static_cast<int>(window->info.size.x),
                                          static_cast<int>(window->info.size.y));

    WindowManager::makeActive(window);
    window->initLayout();
}

void Window::refresh() const {
    glutSetWindow(info.id);
    glutPostRedisplay();
}


//------------------------------------------------------------------------------



