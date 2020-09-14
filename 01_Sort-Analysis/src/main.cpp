#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "sort_analyser.hpp"

Window* Window::current_window = nullptr;

int main(int argc, char** argv) {

    Application* app = new SortAnalyser();

    app->run(&argc, argv);

    delete app;

    return 0;
}


