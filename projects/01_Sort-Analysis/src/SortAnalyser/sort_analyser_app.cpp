#include "SortAnalyser/sort_analyser_app.hpp"
#include "ShishGL/ShishGL.hpp"


const std::vector<SortAnalyserApp::Sort> SortAnalyserApp::SORTS = {
    {"Bubble Sort", SortingWrap(bubble_sort, fill_random), {RED,   255}},
    {"Merge Sort",  SortingWrap(merge_sort,  fill_random), {GREEN, 255}}
};


SortAnalyserApp::SortAnalyserApp()
    : ShishGL::MainWindow("Sort Analyser", 1024, 720) {
    ShishGL::printLog("created app");
}


void SortAnalyserApp::initLayout() {

    static const size_t BUTTON_WIDTH  = 100,
                        BUTTON_HEIGHT = 40;

    Window* graphs = new GraphContainer(0, 0);
    attach(graphs);

    const int buttons_y = static_cast<int>(graphs->getInfo().height);

    int i = 0;
    for (; i < static_cast<int>(SORTS.size()); ++i) {
        attach( new ShishGL::Button(SORTS[i].name,
                                    {graphs, i},
                                    BUTTON_WIDTH * i, buttons_y,
                                    BUTTON_WIDTH, BUTTON_HEIGHT,
                                    SORTS[i].color) );

    }

    attach( new ShishGL::Button("Clean",
                                {graphs, CLEAN_SIGNAL},
                                BUTTON_WIDTH * i, buttons_y,
                                BUTTON_WIDTH, BUTTON_HEIGHT) );
}


void SortAnalyserApp::onRender() {

    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}

