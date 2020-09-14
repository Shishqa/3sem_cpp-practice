#include <cstdio>
#include <cstdlib>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "application.hpp"


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    //glutInitContextVersion(3, 3);
    //glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
    //glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInitWindowSize(1600, 800);
    glutCreateWindow("sort analysis graph");

    glutDisplayFunc(onRender);
    glutReshapeFunc(onReshape);

    glutMainLoop();

    return 0;
}
