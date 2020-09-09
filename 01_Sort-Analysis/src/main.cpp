#include <GL/freeglut.h>
#include <GL/gl.h>

#include "../include/application.hpp"


int main(int argc, char** argv) {

    // init GLUT and create Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("plot");




    // register callbacks
    glutDisplayFunc(onRender);
    //glutIdleFunc(onIdle);
    glutReshapeFunc(onReshape);

    glLineWidth(1.0);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0;
}




