#include <cstdio>
#include <stdexcept>

#include <GL/freeglut.h>

#include "ShishGL/window.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


WindowManager::WindowMap& WindowManager::ActiveWindows() {
    static WindowMap ACTIVE_WINDOWS;
    return ACTIVE_WINDOWS;
}


void WindowManager::makeActive(Window* window) {

    if (!window) {
        printLog("Warning: tried to make NULL window active!");
        return;
    } else if (!window->info.id) {
        printLog("Warning: tried to make uninitialized window %p active!",
                 reinterpret_cast<void*>(window));
        return;
    }

    glutSetWindow(window->info.id);

    glutIdleFunc(manageOnIdle);
    glutDisplayFunc(manageOnRender);
    glutEntryFunc(manageOnEntry);
    glutReshapeFunc(manageOnReshape);
    glutMouseFunc(manageOnMouseClick);
    glutKeyboardFunc(manageOnKeyPress);

    ActiveWindows()[window->info.id] = window;

    printLog("Window %p is now active with id %d (make sure it was initialized before!)",
             reinterpret_cast<void*>(window), window->info.id);

}


Window* WindowManager::getCurrentActiveWindow() {
    const int active_win_id = glutGetWindow();
    try {
        return ActiveWindows().at(active_win_id);
    } catch (const std::out_of_range&) {
        return nullptr;
    }
}


void WindowManager::manageOnIdle() {
    EventSystem::processNewEvents();
    for (const auto& win : ActiveWindows()) {
        if (win.second) {
            win.second->onIdle();
        }
    }
}


void WindowManager::manageOnRender() {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onRender();
    }
}


void WindowManager::manageOnEntry(int state) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onEntry(state);
    }
}


void WindowManager::manageOnReshape(int width, int height) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onReshape(width, height);
    }
}


void WindowManager::manageOnKeyPress(unsigned char key, int x, int y) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onKeyPress(key, x, y);
    }
}


void WindowManager::manageOnMouseClick(int button, int state, int x, int y) {
    Window* win_ptr = getCurrentActiveWindow();
    if (win_ptr) {
        win_ptr->onMouseClick(button, state, x, y);
    }
}
