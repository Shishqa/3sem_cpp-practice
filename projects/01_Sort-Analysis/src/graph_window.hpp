#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP


#include "../include/openGL_util/window.hpp"


class GraphWindow : public Window {
public:

    GraphWindow() = delete;

    GraphWindow(const int& pos_x, const int& pos_y,
                const size_t& width, const size_t& height);

    struct GraphDot {
        double x, y;
    };

    struct Graph {
        double (* function)(double);
        std::vector<GraphDot> dots;
    };

private:

    void onRender() override;

    void onReshape(int, int) override {

        printf("reshaping\n");

    };

    void onKeyPress(unsigned char, int, int) override {};

    void onMouseClick(int, int, int x, int y) override {

        printf("clicked graph at (%d, %d)\n", x, y);

    };

};


#endif //GRAPH_WINDOW_HPP
