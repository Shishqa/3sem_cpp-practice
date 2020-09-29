#include "ShishGL/main_window.hpp"
#include "ShishGL/log.hpp"

#include <GL/freeglut.h>

using namespace ShishGL;


MainWindow::MainWindow(const std::string_view& window_title,
                       const Vector2<size_t>& size)
        : Window({0, 0}, size)
        , title(window_title) {

    glutInitWindowPosition(info.pos.x, info.pos.y);
    glutInitWindowSize(static_cast<int>(info.size.x), static_cast<int>(info.size.y));

    info.id = glutCreateWindow(title.data());
    printLog("Window %p initialized with GLUT with id %d (but still not activated)",
             reinterpret_cast<void*>(this), info.id);

    WindowManager::makeActive(this);
}


void MainWindow::run() {

    initLayout();

    ShishGL::enterMainLoop();
}

