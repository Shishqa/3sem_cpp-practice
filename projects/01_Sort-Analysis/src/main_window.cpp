#include "main_window.hpp"
#include "log.hpp"

using namespace ShishGL;


MainWindow::MainWindow(const char* title,
                       const size_t& width, const size_t& height)
        : Window(0, 0, width, height)
        , title(title) {

    glutInitWindowPosition(info.pos_x, info.pos_y);
    glutInitWindowSize(info.width, info.height);

    info.id = glutCreateWindow(title);
    printLog("Window %p initialized with GLUT with id %d (but still not activated)", this, info.id);

    makeActive(this);

}


MainWindow::~MainWindow() { }

