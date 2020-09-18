#include "SortAnalyser/sort_analyser_app.hpp"
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

    current_min_x = std::min(x, current_min_x);
    current_max_x = std::max(x, current_max_x);

    current_min_y = std::min(y, current_min_y);
    current_max_y = std::max(y, current_max_y);

    refresh();
}


void GraphWindow::clear() {

    curves.clear();
    refresh();

    current_min_x = +std::numeric_limits<double>::infinity();
    current_min_y = +std::numeric_limits<double>::infinity();
    current_max_x = -std::numeric_limits<double>::infinity();
    current_max_y = -std::numeric_limits<double>::infinity();

}


void GraphWindow::onRender() {

    fillWithColor({BLACK, 255});

    drawAxes();

    for (const auto& curve : curves) {

        glColor4ub(curve.line_color.r,
                   curve.line_color.g,
                   curve.line_color.b,
                   curve.line_color.a);
        glLineWidth(3.0f);

        glBegin(GL_LINE_STRIP);
        for (const auto& point : curve.points) {
            // TODO: fix random numbers
            glVertex2d(2 * point.x / (current_max_x - current_min_x) + X_ZERO,
                       2 * point.y / (current_max_y - current_min_y) + Y_ZERO);
        }
        glEnd();
    }

    glutSwapBuffers();

}


void GraphWindow::drawAxes() {

    glColor4ub(WHITE, 255);

    glBegin(GL_LINE_STRIP);
        glVertex2d(X_ZERO,    0.9);
        glVertex2d(X_ZERO, Y_ZERO);
        glVertex2d(   0.9, Y_ZERO);
    glEnd();

}
