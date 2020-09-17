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
                        BUTTON_HEIGHT = 40;

    Window* graphs = new GraphContainer(0, 0);
    attach(graphs);

    const int buttons_y = static_cast<int>(graphs->getInfo().height);

    size_t i = 0;
    for (; i < sizeof(SORTS) / sizeof(Sort); ++i) {
        attach( new ShishGL::Button(SORTS[i].name,
                                    {graphs, static_cast<int>(i)},
                                    BUTTON_WIDTH * i, buttons_y,
                                    BUTTON_WIDTH, BUTTON_HEIGHT,
                                    SORTS[i].color) );

    }

    attach( new ShishGL::Button("Clear",
                                {graphs, CLEAR_SIGNAL},
                                BUTTON_WIDTH * i, buttons_y,
                                BUTTON_WIDTH, BUTTON_HEIGHT) );
}


void SortAnalyserWindow::onRender() {

    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}

