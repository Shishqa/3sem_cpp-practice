#include "SortAnalyser/graph_window.hpp"
using namespace SortAnalyser;


GraphWindow::GraphWindow(const int& pos_x, const int& pos_y,
                         const size_t& width, const size_t& height)
        : Window(pos_x, pos_y, width, height) { }


unsigned int GraphWindow::initCurve(const Color& color) {

    curves.push_back({color, {}});
    return static_cast<unsigned int>(curves.size()) - 1;

}


void GraphWindow::addPoint(const int& curve_id, double x, double y) {

    curves.at(curve_id).points.push_back({x, y});
    refresh();

}


void GraphWindow::clear() {

    curves.clear();
    refresh();

}


void GraphWindow::onRender() {

    fillWithColor({BLACK, 255});

    drawAxes();

    for (const auto& curve : curves) {

        glColor4ub(curve.line_color.r,
                   curve.line_color.g,
                   curve.line_color.b,
                   curve.line_color.a);
        glLineWidth(2.0f);

        glBegin(GL_LINE_STRIP);
        for (const auto& point : curve.points) {
            glVertex2d(point.x / 600 - 0.9, point.y / 100000 - 0.9);
        }
        glEnd();
    }

    glutSwapBuffers();

}


void GraphWindow::drawAxes() {

    glColor4ub(WHITE, 255);

    glBegin(GL_LINE_STRIP);
        glVertex2d(-0.9,  0.9);
        glVertex2d(-0.9, -0.9);
        glVertex2d( 0.9, -0.9);
    glEnd();

}
