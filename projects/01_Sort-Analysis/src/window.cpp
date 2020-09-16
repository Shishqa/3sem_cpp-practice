#include "window.hpp"
#include "log.hpp"

using namespace ShishGL;


Window::Window(const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height)
        : info({ID_UNDEFINED, pos_x, pos_y, width, height}) {

    printLog("Created window %p at (%d, %d) with width %lu px and height %lu px (but not initialised with GLUT)",
             this, pos_x, pos_y, width, height);
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


void Window::attach(Window* window) {

    subwindows.emplace_back(window);

}


//------------------------------------------------------------------------------


Window* Window::active_windows[MAX_ALLOWED_WINDOW_CNT + 1] = {};


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
             window, window->info.id);

//    for (auto& win : window->subwindows) {
//
//        win->info.id = glutCreateSubWindow(window->info.id,
//                                           win->info.pos_x, win->info.pos_y,
//                                           win->info.width, win->info.height);
//
//        printLog("Window %p initialized with GLUT with id %d", win, win->info.id);
//
//        makeActive(win);
//    }

}


Window* Window::getCurrentActiveWindow() {

    const int active_win_id = glutGetWindow();

    if (active_win_id <= MAX_ALLOWED_WINDOW_CNT) {
        return active_windows[active_win_id];
    }

    return nullptr;
}


void Window::manageOnIdle() {
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
