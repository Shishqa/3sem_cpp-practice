#include "SortAnalyser/sort_analyser_window.hpp"
#include "SortAnalyser/graph_container.hpp"
#include "ShishGL/ShishGL.hpp"

using namespace SortAnalyser;


SortAnalyserWindow::SortAnalyserWindow()
        : ShishGL::Window({1024, 720}, {0, 0}, "Sort Analyser") {

    static const size_t
            BUTTON_WIDTH = 100,
            BUTTON_HEIGHT = 40,
            BUTTON_GAP = 10;

    static const int GAP = static_cast<int>(info.size.x - GraphContainer::CONTAINER_WIDTH) / 2;

    Window* graphs = new GraphContainer({GAP, GAP});
    attach(graphs);

    printLog("Graphs: %p", reinterpret_cast<void*>(graphs));

    Vector2<int> buttons_pos = {GAP, static_cast<int>(GAP + GraphContainer::CONTAINER_HEIGHT + BUTTON_GAP)};

    for (size_t i = 0; i < Sorts().size(); ++i) {
        attach(new ShishGL::Button(
                Sorts()[i].name,
                {graphs, static_cast<int>(i)},
                Vector2<int>{static_cast<int>(BUTTON_WIDTH * i + BUTTON_GAP * i), 0} +
                buttons_pos, {BUTTON_WIDTH, BUTTON_HEIGHT},
                {Sorts()[i].color, MINT_CREAM, WHITE, BLACK}
        ));
    }
    buttons_pos.y += BUTTON_HEIGHT + BUTTON_GAP;

    for (size_t i = 0; i < sizeof(UTIL_BUTTONS) / sizeof(ButtonDescription); ++i) {
        attach(new ShishGL::Button(
                UTIL_BUTTONS[i].name,
                {graphs, UTIL_BUTTONS[i].event_signal},
                Vector2<int>{static_cast<int>(2 * BUTTON_WIDTH * i + BUTTON_GAP * i), 0} +
                buttons_pos, {2 * BUTTON_WIDTH, BUTTON_HEIGHT},
                {UTIL_BUTTONS[i].color, MINT_CREAM, WHITE, BLACK}
        ));
    }
}


void SortAnalyserWindow::onRender() {
    renderBegin(info.size);

    ShishGL::fillWithColor(DIM_GRAY);

    renderEnd();
}


void SortAnalyserWindow::onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}
