#include "ShishGL/ShishGL.hpp"
#include "SortAnalyser/sort_analyser_window.hpp"

using namespace SortAnalyser;


int main(int argc, char** argv) {

    ShishGL::init(&argc, argv);

    MainWindow* app = new SortAnalyserWindow();

    app->run();

    delete app;

    ShishGL::terminate();

    return 0;
}
