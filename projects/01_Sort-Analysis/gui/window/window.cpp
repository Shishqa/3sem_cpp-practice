#include <GL/freeglut.h>
#include <GL/gl.h>

#include "window.hpp"


Window::Window(const char* title
               int pos_x, int pos_y,
               int width, int height) {

    glutInitWindowPosition(pos_x, pos_y);
    glutInitWindowSize(width, height);
    id = glutCreateWindow(title);
}


Window::Window()
    : id(-1) {}
