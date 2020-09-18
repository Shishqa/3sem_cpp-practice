#ifndef SORT_ANALYSER_WINDOW_HPP
#define SORT_ANALYSER_WINDOW_HPP

#include "graph_container.hpp"

#include "ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "sort_analyser_app.hpp"


namespace SortAnalyser {

    class SortAnalyserWindow : public ShishGL::MainWindow {
    public:

        SortAnalyserWindow();

        ~SortAnalyserWindow() override = default;

    private:

        void initLayout() override;

        void onRender() override;

        friend GraphContainer;
        friend GraphWindow;
    };

}

#endif //SORT_ANALYSER_WINDOW_HPP