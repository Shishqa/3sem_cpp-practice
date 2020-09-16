#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "essential.hpp"

#include "button.hpp"

int main(int argc, char** argv) {

    ShishGL::init(&argc, argv, ShishGL::DEBUG);

    ShishGL::Window* win1 = new ShishGL::Button("hello!", 0, 0, 300, 100,
                                                {0, 100, 0, 255},
                                                {0, 250, 154, 255},
                                                {224, 255, 255, 255} );

    glutInitWindowSize(win1->info.width, win1->info.height);
    win1->info.id = glutCreateWindow(nullptr);
    ShishGL::Window::makeActive(win1);

    ShishGL::run();

    delete win1;

    ShishGL::terminate();

    return 0;
}

