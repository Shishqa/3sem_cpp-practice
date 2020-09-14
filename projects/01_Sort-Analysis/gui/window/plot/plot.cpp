#include <GL/freeglut.h>
#include <GL/gl.h>

#include "plot.hpp"


PlotWindow::PlotWindow(int (*function)(int),
                       int parent, int pos_x, int pos_y,
                       int height, int width)
    : Window(parent, pos_x, pos_y, height, width)
    , function(function) {}


void PlotWindow::onDraw() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Black Background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutSwapBuffers();

}



