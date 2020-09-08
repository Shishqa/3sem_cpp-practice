#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <cstddef>

class Application {
public:

    Application() = delete;

    Application(int* argc_ptr, char** argv);

    void run();

private:

    const size_t INIT_WINDOW_HEIGHT = 640, // px
                 INIT_WINDOW_WIDTH  = 640, // px
                 INIT_GAP           = 10;  // px

    int mainWindow,
        plotAssignmentWindow,
        plotComparisonWindow,
        sortSelectionWindow;

    void initWindowLayout();

    void initHandlers();

    static void renderBackground();

    static void renderSubwindow();

    static void changeSize(int width, int height);
};

#endif //APPLICATION_HPP
