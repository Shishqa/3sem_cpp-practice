#ifndef PLOT_WINDOW_HPP
#define PLOT_WINDOW_HPP


#include "../window.hpp"

class PlotWindow : public Window {
public:

    PlotWindow() = delete;

    PlotWindow(int (* function)(int),
               int parent, int pos_x, int pos_y,
               int height, int width);

private:

    int (* function)(int); // displayed func

    void onDraw() override;

    void onReshape(int width, int height) override;

    void onKeyPress(unsigned char key, int x, int y) override;

    void onMouseClick(int button, int state, int x, int y) override;
};


#endif //PLOT_WINDOW_HPP
