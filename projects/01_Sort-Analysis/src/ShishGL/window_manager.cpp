#include <stdexcept>

#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

#include "ShishGL/window_manager.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


int WindowManager::initialize() {

    static bool IS_INITIALIZED = false;
    if (IS_INITIALIZED) {
        return 0;
    }

    display = XOpenDisplay(nullptr);
    if (!display) {
        printLog("Error: cannot connect to X-server!");
        return 0;
    }

    IS_INITIALIZED = true;
    return 1;
}


WindowManager::WindowMap& WindowManager::ActiveWindows() {
    static WindowMap ACTIVE_WINDOWS;
    return ACTIVE_WINDOWS;
}


void WindowManager::makeActive(Window* window) {

    if (!window) {
        printLog("Warning: tried to make NULL window active!");
        return;
    } else if (window->info.id != Window::ID_UNDEFINED) {
        printLog("Warning: tried to activate window twice!");
        return;
    }

    int blackColor = BlackPixel(display, DefaultScreen(display));

    window->info.id = XCreateSimpleWindow(display,
                                          XDefaultRootWindow(display),
                                          window->info.pos.x, window->info.pos.y,
                                          window->info.size.x, window->info.size.y,
                                          0, blackColor, blackColor);

    activate(window);

    XMapSubwindows(display, window->info.id);
}


void WindowManager::activate(Window* window) {

    XSelectInput(display, window->info.id, StructureNotifyMask);

    ActiveWindows()[window->info.id] = window;
    setHandlers(window);

    printLog("Window %p is now active with id %lu",
             reinterpret_cast<void*>(window), window->info.id);

    int blackColor = BlackPixel(display, DefaultScreen(display));

    for (const auto& p_subwindow : window->subwindows) {

        window->info.id = XCreateSimpleWindow(display,
                                              window->info.id,
                                              window->info.pos.x, window->info.pos.y,
                                              window->info.size.x, window->info.size.y,
                                              0, blackColor, blackColor);

        activate(p_subwindow);
    }
}


void WindowManager::makeInactive(Window* window) {

    if (!window) {
        printLog("Warning: tried to deactivate NULL window!");
        return;
    } else if (window->info.id == Window::ID_UNDEFINED) {
        //printLog("Warning: tried to deactivate not active window!");
        return;
    }

    for (const auto& p_subwindow : window->subwindows) {
        makeInactive(p_subwindow);
    }

    ActiveWindows().erase(window->info.id);
    glutDestroyWindow(window->info.id);

    window->info.id = Window::ID_UNDEFINED;

    printLog("Window %p is now inactive", reinterpret_cast<void*>(window));
}


void WindowManager::setHandlers(Window* window) {

    glutSetWindow(window->info.id);

    glutIdleFunc(manageOnIdle);
    glutDisplayFunc(manageOnRender);
    glutEntryFunc(manageOnEntry);
    glutReshapeFunc(manageOnReshape);
    glutMouseFunc(manageOnMouseClick);
    glutKeyboardFunc(manageOnKeyPress);
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
