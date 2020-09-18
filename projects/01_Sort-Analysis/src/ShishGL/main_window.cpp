#include "ShishGL/main_window.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


MainWindow::MainWindow(const char* window_title,
                       const size_t& width, const size_t& height)
        : Window(0, 0, width, height)
        , title(window_title) {

    glutInitWindowPosition(info.pos_x, info.pos_y);
    glutInitWindowSize(static_cast<int>(info.width), static_cast<int>(info.height));

    info.id = glutCreateWindow(title);
    printLog("Window %p initialized with GLUT with id %d (but still not activated)",
             reinterpret_cast<void*>(this), info.id);

    makeActive(this);
}


void MainWindow::run() {

    initLayout();

    ShishGL::startMainLoop();
}

