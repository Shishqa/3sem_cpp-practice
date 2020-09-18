#ifndef GRAPH_CONTAINER_HPP
#define GRAPH_CONTAINER_HPP

#include "ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "sort_analyser_app.hpp"
#include "graph_window.hpp"

#include <limits>

namespace SortAnalyser {

    class GraphContainer : public ShishGL::Window {
    public:

        GraphContainer() = delete;

        GraphContainer(const int& pos_x, const int& pos_y);

        ~GraphContainer() override = default;

    private:

        GraphWindow* assignments_graph;
        GraphWindow* comparisons_graph;

        enum {
            GRAPH_WINDOWS_GAP   = 30,
            GRAPH_WINDOW_WIDTH  = 400,
            GRAPH_WINDOW_HEIGHT = 400
        };

        void initLayout() override;

        void onRender() override;

        void processEvent(const Event &) override;

        void displaySortStat(const Sort& sort);

        void clear();

    };

}




#endif //GRAPH_CONTAINER_HPP
