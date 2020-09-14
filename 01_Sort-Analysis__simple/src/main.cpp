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
    int main_window = glutCreateWindow("sort analysis graph");

    glutDisplayFunc(onRender);
    glutReshapeFunc(onReshape);

    int sort_selection_menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("CLEAR", CLEAR);
    glutAddMenuEntry("UPDATE", UPDATE);
    glutAddMenuEntry("BUBBLE SORT", BUBBLE_SORT);
    glutAddMenuEntry("MERGE SORT", MERGE_SORT);
    glutAddMenuEntry("STD SORT", STD_SORT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    glutDestroyMenu(sort_selection_menu);
    glutDestroyWindow(main_window);

    return 0;
}
