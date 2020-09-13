#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP


#include "../include/openGL_util/window.hpp"


class GraphWindow : public Window {
public:

    GraphWindow() = delete;

    GraphWindow(const int& pos_x, const int& pos_y,
                const size_t& width, const size_t& height)
                : Window(pos_x, pos_y, width, height) { }

    virtual void set() { }

    struct GraphDot {
        double x, y;
    };

private:

    std::vector<GraphDot> dots;



};


#endif //GRAPH_WINDOW_HPP
