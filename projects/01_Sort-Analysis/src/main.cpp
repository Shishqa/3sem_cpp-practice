#include "ShishGL/ShishGL.hpp"
#include "SortAnalyser/sort_analyser_app.hpp"


int main(int argc, char** argv) {

    ShishGL::init(&argc, argv);

    auto app = new SortAnalyserApp();
    app->show();

    delete app;

    ShishGL::terminate();

    return 0;
}
