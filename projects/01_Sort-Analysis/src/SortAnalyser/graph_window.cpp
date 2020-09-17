#include "SortAnalyser/sort_analyser_app.hpp"


SortAnalyserApp::GraphContainer::GraphWindow::GraphWindow(const int& pos_x, const int& pos_y,
                                                          const size_t& width, const size_t& height)
        : Window(pos_x, pos_y, width, height) { }


void SortAnalyserApp::GraphContainer::GraphWindow::onRender() {

    fillWithColor({BLACK, 255});

    drawAxes();

    glutSwapBuffers();

}


void SortAnalyserApp::GraphContainer::GraphWindow::drawAxes() {

    glColor4ub(WHITE, 255);

    glBegin(GL_LINE_STRIP);
        glVertex2d(-0.9,  0.9);
        glVertex2d(-0.9, -0.9);
        glVertex2d( 0.9, -0.9);
    glEnd();

}
