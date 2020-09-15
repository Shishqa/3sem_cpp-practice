#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "essential.hpp"

int main(int argc, char** argv) {

    ShishGL::init(&argc, argv, ShishGL::DEBUG);

    printf("hello, world!\n");

    ShishGL::terminate();

    return 0;
}
