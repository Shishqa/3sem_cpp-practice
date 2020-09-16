#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "essential.hpp"

#include "sort_analyser_app.hpp"


int main(int argc, char** argv) {

    ShishGL::init(&argc, argv, ShishGL::DEBUG);

    SortAnalyserApp* app = new SortAnalyserApp();

    ShishGL::run();

    delete app;

    ShishGL::terminate();

    return 0;
}

