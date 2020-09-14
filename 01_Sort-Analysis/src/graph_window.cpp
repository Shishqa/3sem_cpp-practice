#include "graph_window.hpp"


GraphWindow::GraphWindow(const int& pos_x, const int& pos_y,
                         const size_t& width, const size_t& height)
        : Window(pos_x, pos_y, width, height) {

    printf("graph window created\n");

}


void GraphWindow::onRender() {

    glClearColor(1, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}
