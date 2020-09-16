#include "graph_window.hpp"

using namespace ShishGL;


GraphWindow::GraphWindow(const int& pos_x, const int& pos_y,
                         const size_t& width, const size_t& height)
        : Window(pos_x, pos_y, width, height) { }


GraphWindow::~GraphWindow() {



}

void GraphWindow::onRender() {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}
