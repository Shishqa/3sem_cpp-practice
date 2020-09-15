#include "window.hpp"

using namespace ShishGL;


Window::Window(const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height)
        : info({ID_UNDEFINED, pos_x, pos_y, width, height}) {
    printLog("Created window at (%d, %d) with width %lu px and height %lu px",
             info.id pos_x, pos_y, width, height);
}


Window::~Window() {

    printf("window deleted\n");

    for (auto& window : sub_windows) {
        delete window;
    }
}


void Window::attachSubWindow(Window* window) {



}


void Window::dump()  {

    printf("{ %d ", info.id);

    for (auto& window : sub_windows) {
        window->dump();
    }

    printf("}");
}
