#include "SortAnalyser/sort_analyser_window.hpp"
#include "SortAnalyser/graph_container.hpp"
#include "ShishGL/ShishGL.hpp"

using namespace SortAnalyser;


SortAnalyserWindow::SortAnalyserWindow()
    : ShishGL::MainWindow("Sort Analyser", 1024, 720) {
    ShishGL::printLog("created app");
}


void SortAnalyserWindow::initLayout() {

    static const size_t BUTTON_WIDTH  = 100,
                        BUTTON_HEIGHT = 40,
                        BUTTON_GAP    = 10;

    Window* graphs = new GraphContainer(0, 0);
    attach(graphs);

    int buttons_y = static_cast<int>(graphs->getInfo().height + BUTTON_GAP);

    for (size_t i = 0; i < sizeof(SORTS) / sizeof(Sort); ++i) {
        attach( new ShishGL::Button(SORTS[i].name,
                                    {graphs, static_cast<int>(i)},
                                    static_cast<int>(BUTTON_WIDTH * i + BUTTON_GAP * i),
                                    buttons_y,
                                    BUTTON_WIDTH, BUTTON_HEIGHT,
                                    SORTS[i].color) );

    }
    buttons_y += BUTTON_HEIGHT + BUTTON_GAP;

    for (size_t i = 0; i < sizeof(UTIL_BUTTONS) / sizeof(ButtonDescription); ++i) {
        attach( new ShishGL::Button(UTIL_BUTTONS[i].name,
                                    {graphs, UTIL_BUTTONS[i].event_signal},
                                    static_cast<int>(2 * BUTTON_WIDTH * i + BUTTON_GAP * i),
                                    buttons_y,
                                    2 * BUTTON_WIDTH, BUTTON_HEIGHT,
                                    UTIL_BUTTONS[i].color) );
    }

}


void SortAnalyserWindow::onRender() {

    fillWithColor({DIM_GRAY, 255});

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}

