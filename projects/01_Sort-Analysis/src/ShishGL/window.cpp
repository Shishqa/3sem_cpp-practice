#include <cstdio>
#include <stdexcept>

#include <GL/freeglut.h>

#include "ShishGL/window.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


Window* Window::active_windows[MAX_ALLOWED_WINDOW_CNT + 1] = {};


Window::Window(const Vector2<int>& position,
               const Vector2<size_t>& size)
        : info({ID_UNDEFINED, position, size}) {

    printLog("Created main window %p at (%d, %d) %lux%lupx (but not initialised with GLUT)",
             reinterpret_cast<void*>(this), position.x, position.y, size.x, size.y);
}


Window::~Window() {

    for (auto& win : subwindows) {
        delete win;
    }

    printLog("Destroyed window %d", info.id);
}


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

    if (info.id == ID_UNDEFINED) {
        printLog("Warning: attached subwindow to not-initialized window!");
        return;
    }

    window->info.id = glutCreateSubWindow(info.id,
                                          window->info.pos.x, window->info.pos.y,
                                          static_cast<int>(window->info.size.x),
                                          static_cast<int>(window->info.size.y));

    makeActive(window);

    window->initLayout();
}


//------------------------------------------------------------------------------


void Window::makeActive(Window* window) {

    if (!window) {
        printLog("Warning: tried to make NULL window active!");
        return;
    }

    if (!window->info.id) {
        printLog("Warning: tried to make uninitialized window active!");
        return;
    } else if (window->info.id > MAX_ALLOWED_WINDOW_CNT) {
        printLog("Error: trying to make active window{%d} with id greater than %d!",
                 window->info.id, MAX_ALLOWED_WINDOW_CNT);
        throw std::runtime_error("Error: huge id!");
    }

    glutSetWindow(window->info.id);

    glutIdleFunc(manageOnIdle);
    glutDisplayFunc(manageOnRender);
    glutEntryFunc(manageOnEntry);
    glutReshapeFunc(manageOnReshape);
    glutMouseFunc(manageOnMouseClick);
    glutKeyboardFunc(manageOnKeyPress);

    active_windows[window->info.id] = window;

    printLog("Window %p is now active with id %d (make sure it was initialized before!)",
             reinterpret_cast<void*>(window), window->info.id);

}


Window* Window::getCurrentActiveWindow() {

    const int active_win_id = glutGetWindow();

    if (active_win_id <= MAX_ALLOWED_WINDOW_CNT) {
        return active_windows[active_win_id];
    }

    return nullptr;
}


void Window::refresh() const {
    glutSetWindow(info.id);
    glutPostRedisplay();
}


void Window::manageOnIdle() {
    EventSystem::processNewEvents();
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onIdle();
    }
}


void Window::manageOnRender() {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onRender();
    }
}


void Window::manageOnEntry(int state) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onEntry(state);
    }
}


void Window::manageOnReshape(int width, int height) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onReshape(width, height);
    }
}


void Window::manageOnKeyPress(unsigned char key, int x, int y) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onKeyPress(key, x, y);
    }
}


void Window::manageOnMouseClick(int button, int state, int x, int y) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onMouseClick(button, state, x, y);
    }
}


//------------------------------------------------------------------------------
