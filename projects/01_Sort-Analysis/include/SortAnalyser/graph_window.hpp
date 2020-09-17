#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP


#include "ShishGL/ShishGL.hpp"
using namespace ShishGL;

namespace SortAnalyser {

    class GraphWindow : public ShishGL::Window {
    public:

        struct Curve {
            Color line_color;

            struct Point {
                double x, y;
            };

            std::vector<Point> points;
        };

        GraphWindow() = delete;

        GraphWindow(const int& pos_x, const int& pos_y,
                    const size_t& width, const size_t& height);

        ~GraphWindow() override = default;

        unsigned int initCurve(const Color& color);

        void addPoint(const int& curve_id, double x, double y);

        void clear();

    private:

        std::vector<Curve> curves;

        void onRender() override;

        void drawAxes();

    };

}


#endif //GRAPH_WINDOW_HPP
