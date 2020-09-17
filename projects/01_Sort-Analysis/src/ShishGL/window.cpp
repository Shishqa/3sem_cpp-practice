#include "ShishGL/window.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


Window::Window(const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height)
        : info({ID_UNDEFINED, pos_x, pos_y, width, height}) {

    printLog("Created main window %p at (%d, %d) with width %lu px and height %lu px (but not initialised with GLUT)",
             reinterpret_cast<void*>(this), pos_x, pos_y, width, height);
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
                                          window->info.pos_x, window->info.pos_y,
                                          static_cast<int>(window->info.width),
                                          static_cast<int>(window->info.height));

    makeActive(window);

    window->initLayout();

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
    processNewEvents();
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


std::queue<Event> Window::events;


void Window::generateEvent(const Event& event) {
    events.push(event);
}


void Window::processNewEvents() {

    while (!events.empty()) {

        Event curr_event = events.front();

        if (!curr_event.target) {
            printLog("Warning: event with empty target passed!");
        } else {
            curr_event.target->processEvent(curr_event);
        }

        events.pop();

    }

}
