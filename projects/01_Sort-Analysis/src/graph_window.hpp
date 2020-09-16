#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP

#include <cstddef>
#include "window.hpp"

namespace ShishGL {

    class GraphWindow : public Window {
    public:

        GraphWindow() = delete;

        GraphWindow(const int& pos_x, const int& pos_y,
                    const size_t& width, const size_t& height);

        virtual ~GraphWindow();

    private:

        void onRender() override;

    };

}




#endif //GRAPH_WINDOW_HPP
