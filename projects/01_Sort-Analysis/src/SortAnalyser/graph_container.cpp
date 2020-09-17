#include "SortAnalyser/graph_container.hpp"
#include "SortAnalyser/graph_window.hpp"
using namespace SortAnalyser;


GraphContainer::GraphContainer(const int& pos_x, const int& pos_y)
        : ShishGL::Window(pos_x, pos_y,
                          GRAPH_WINDOW_WIDTH * 2 + GRAPH_WINDOWS_GAP * 3,
                          GRAPH_WINDOW_HEIGHT    + GRAPH_WINDOWS_GAP * 2)
        , assignments_graph(nullptr)
        , comparisons_graph(nullptr) { }


void GraphContainer::initLayout() {

    assignments_graph = new GraphWindow(GRAPH_WINDOWS_GAP, GRAPH_WINDOWS_GAP,
                                         GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT);

    comparisons_graph = new GraphWindow(GRAPH_WINDOWS_GAP * 2 + GRAPH_WINDOW_WIDTH, GRAPH_WINDOWS_GAP,
                                        GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT);

    attach(assignments_graph);
    attach(comparisons_graph);

}


void GraphContainer::onRender() {

    fillWithColor({KHAKI, 255});

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();

}


void GraphContainer::processEvent(const Event& event) {

    if (event.event_code == CLEAR_SIGNAL) {
        clear();
    } else {
        displaySortStat(SORTS[event.event_code]);
    }

}


void GraphContainer::clear() {

    assignments_graph->clear();
    comparisons_graph->clear();

}


void GraphContainer::displaySortStat(const Sort& sort) {

    static const size_t
            MIN_ARRAY_SIZE = 100,
            MAX_ARRAY_SIZE = 1000,
            NUM_OF_DOTS    = 100,
            STEP           = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / NUM_OF_DOTS;

    uint32_t assign_id  = assignments_graph->initCurve(sort.color);
    uint32_t compare_id = comparisons_graph->initCurve(sort.color);

    for (size_t array_size = MIN_ARRAY_SIZE; array_size < MAX_ARRAY_SIZE; array_size += STEP) {

        Stat stat = sort.stat_function(array_size);

        assignments_graph->addPoint(assign_id,  static_cast<double>(array_size),
                                    static_cast<double>(stat.assign_cnt));

        comparisons_graph->addPoint(compare_id, static_cast<double>(array_size),
                                    static_cast<double>(stat.compare_cnt));

    }

}
