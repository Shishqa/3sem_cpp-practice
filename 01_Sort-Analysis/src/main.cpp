#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "sort_analyser.hpp"

Window* Window::current_window = nullptr;

int main(int argc, char** argv) {

    Application* app = new SortAnalyser();
    printf("analyser created\n");

    app->init(&argc, argv);
    printf("analyser initiated\n");

    app->run();

    delete app;

    return 0;
}
