#ifndef SORT_ANALYSER_APP_HPP
#define SORT_ANALYSER_APP_HPP


#include "ShishGL/colors.hpp"
#include "ShishGL/main_window.hpp"

#include "sorting_wrap.hpp"
#include "sort_collection.hpp"

using namespace ShishGL;


class SortAnalyserApp : public ShishGL::MainWindow {
public:

    SortAnalyserApp();

    ~SortAnalyserApp() override = default;

    struct Sort {
        const char* name;
        SortingWrap stat_function;
        Color       color;
    };

    class GraphContainer : public ShishGL::Window {
    public:

        GraphContainer() = delete;

        GraphContainer(const int& pos_x, const int& pos_y);

        ~GraphContainer() override = default;

        class GraphWindow : public ShishGL::Window {
        public:

            GraphWindow() = delete;

            GraphWindow(const int& pos_x, const int& pos_y,
                        const size_t& width, const size_t& height);

            ~GraphWindow() override = default;

        private:

            void onRender() override;

            void drawAxes();

        };

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

    };


private:

    enum {
        CLEAN_SIGNAL = -1,
    };

    static const std::vector<Sort> SORTS;

    void initLayout() override;

    void onRender() override;

};


#endif //SORT_ANALYSER_APP_HPP
