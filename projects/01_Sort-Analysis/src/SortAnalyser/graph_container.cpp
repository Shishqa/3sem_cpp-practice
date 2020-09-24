#include "ShishGL/ShishGL.hpp"
#include "SortAnalyser/graph_container.hpp"
#include "SortAnalyser/graph_window.hpp"

using namespace SortAnalyser;


GraphContainer::GraphContainer(const Vector2<int>& pos)
        : ShishGL::Window(pos, {GRAPH_WINDOW_WIDTH * 2 + GRAPH_WINDOWS_GAP * 3,
                                GRAPH_WINDOW_HEIGHT + GRAPH_WINDOWS_GAP * 2}), assignments_graph(nullptr),
          comparisons_graph(nullptr) {}


void GraphContainer::initLayout() {

    assignments_graph = new GraphWindow({GRAPH_WINDOWS_GAP, GRAPH_WINDOWS_GAP},
                                        {GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT},
                                        "Assignments");

    comparisons_graph = new GraphWindow({GRAPH_WINDOWS_GAP * 2 + GRAPH_WINDOW_WIDTH, GRAPH_WINDOWS_GAP},
                                        {GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT},
                                        "Comparisons");

    attach(assignments_graph);
    attach(comparisons_graph);
}


void GraphContainer::onRender() {
    renderBegin(info.size);

    ShishGL::fillWithColor(DARK_SLATE_GRAY);

    setColor(GREEN);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(100, 100);
        glVertex2d(100, 0);
    glEnd();

    renderEnd();
}


void GraphContainer::onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}


void GraphContainer::getEvent(const Event& event) {

    switch (event.event_code) {

        case CLEAR_SIGNAL:
            clear();
            break;

        case NORMAL_RANGE:
            printf("not yet implemented: normal range [0; 1000] (step = 10)\n");
            break;

        case BIG_RANGE:
            printf("not yet implemented: big range [0; 100000] (step = 1000)\n");
            break;

        default:
            if (event.event_code >= static_cast<int>(Sorts().size()) ||
                0 > event.event_code) {
                printLog("Warning: tried to display curve with id %d", event.event_code);
                break;
            }
            displaySortStat(Sorts()[event.event_code]);
    }

}


void GraphContainer::clear() {

    assignments_graph->clear();
    comparisons_graph->clear();

}


void GraphContainer::displaySortStat(const Sort& sort) {

    uint32_t assign_id = assignments_graph->initCurve(sort.color);
    uint32_t compare_id = comparisons_graph->initCurve(sort.color);

    auto MAX_SIZE = static_cast<size_t>(sort.correction_factor * static_cast<double>(MAX_ARRAY_SIZE));

    for (size_t array_size = MIN_ARRAY_SIZE; array_size < MAX_SIZE; array_size += STEP) {

        Stat stat = sort.stat_function(array_size);

        assignments_graph->addPoint(assign_id, {static_cast<double>(array_size),
                                                static_cast<double>(stat.assign_cnt)});

        comparisons_graph->addPoint(compare_id, {static_cast<double>(array_size),
                                                 static_cast<double>(stat.compare_cnt)});
    }

}
