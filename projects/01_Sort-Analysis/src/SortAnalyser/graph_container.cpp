#include "SortAnalyser/sort_analyser_app.hpp"


SortAnalyserApp::GraphContainer::GraphContainer(const int& pos_x, const int& pos_y)
        : ShishGL::Window(pos_x, pos_y,
                          GRAPH_WINDOW_WIDTH * 2 + GRAPH_WINDOWS_GAP * 3,
                          GRAPH_WINDOW_HEIGHT    + GRAPH_WINDOWS_GAP * 2) { }


void SortAnalyserApp::GraphContainer::initLayout() {

    assignments_graph = new GraphWindow(GRAPH_WINDOWS_GAP, GRAPH_WINDOWS_GAP,
                                         GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT);

    comparisons_graph = new GraphWindow(GRAPH_WINDOWS_GAP * 2 + GRAPH_WINDOW_WIDTH, GRAPH_WINDOWS_GAP,
                                         GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT);

    attach(assignments_graph);
    attach(comparisons_graph);

}


void SortAnalyserApp::GraphContainer::onRender() {

    fillWithColor({KHAKI, 255});

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}


void SortAnalyserApp::GraphContainer::processEvent(const Event& event) {

    if (event.event_code == CLEAN_SIGNAL) {
        printf("Clean\n");
    } else {
        printf("%s\n", SORTS[event.event_code].name);
        displaySortStat(SORTS[event.event_code]);
    }

}


void SortAnalyserApp::GraphContainer::displaySortStat(const Sort& sort) {

    static const size_t MIN_ARRAY_SIZE = 100,
            MAX_ARRAY_SIZE = 10000,
            NUM_OF_DOTS    = 100,
            STEP           = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / NUM_OF_DOTS;

    for (size_t array_size = MIN_ARRAY_SIZE; array_size < MAX_ARRAY_SIZE; array_size += STEP) {

        Stat stat = sort.stat_function(array_size);
        printf("%lu;%lu;%lu\n", array_size, stat.assign_cnt, stat.compare_cnt);

    }

}
