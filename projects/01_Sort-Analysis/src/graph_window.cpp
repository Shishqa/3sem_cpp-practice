#include "graph_window.hpp"
#include "colors.hpp"


using namespace ShishGL;


GraphWindow::GraphWindow(const int& pos_x, const int& pos_y,
                         const size_t& width, const size_t& height)
        : Window(pos_x, pos_y, width, height)
        , curr_color({BLACK, 255}) { }


GraphWindow::~GraphWindow() { }


void GraphWindow::onRender() {

    glClearColor(curr_color.r / 255.,
                 curr_color.g / 255.,
                 curr_color.b / 255.,
                 curr_color.a / 255.);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}


void GraphWindow::processEvent(const Event& event) {

    if (event.event_code == 1) {

        curr_color = {YELLOW, 255};
        refresh();

    }

}
