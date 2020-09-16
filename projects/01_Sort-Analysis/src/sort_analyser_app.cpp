#include "sort_analyser_app.hpp"
#include "button.hpp"
#include "graph_window.hpp"
#include "colors.hpp"
#include "log.hpp"
#include "event.hpp"

SortAnalyserApp::SortAnalyserApp()
    : ShishGL::MainWindow("Sort Analyser", 1024, 720) {

    Window* graph = new ShishGL::GraphWindow(0, 0, 100, 100);

    attach(graph);

    attach(new ShishGL::Button("touch me",
                               {graph, 1},
                               200, 200, 500, 50,
                               {DARK_KHAKI, 255},
                               {KHAKI, 255},
                               {PAPAYA_WHIP, 255}));

    ShishGL::printLog("created app");
}


SortAnalyserApp::~SortAnalyserApp() {
    ShishGL::printLog("deleted app");
}


void SortAnalyserApp::onRender() {

    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}
