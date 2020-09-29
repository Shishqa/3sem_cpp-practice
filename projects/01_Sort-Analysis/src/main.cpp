#include "ShishGL/ShishGL.hpp"
#include "SortAnalyser/sort_analyser_window.hpp"

using namespace SortAnalyser;


int main(int argc, char** argv) {

    ShishGL::init(&argc, argv);

    Window* app = new SortAnalyserWindow();

    app->display();
    ShishGL::enterMainLoop();
    //app->close();

    delete app;

    ShishGL::terminate();

    return 0;
}
