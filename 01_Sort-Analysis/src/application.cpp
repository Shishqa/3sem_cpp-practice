#include <GL/freeglut.h>
#include <GL/gl.h>

#include "../include/application.hpp"


Application::Application(int* argc_ptr, char** argv) {
    glutInit(argc_ptr, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    initWindowLayout();
}


void Application::run() {
    glutMainLoop();
}


void Application::initWindowLayout() {
    glutInitWindowSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
    mainWindow = glutCreateWindow("Sort Analyzer");

    glutDisplayFunc(renderBackground);
    glutReshapeFunc(changeSize);

    plotAssignmentWindow = glutCreateSubWindow(mainWindow,
                                               INIT_GAP,
                                               INIT_GAP,
                                               (INIT_WINDOW_WIDTH - 3 * INIT_GAP) / 2,
                                               (INIT_WINDOW_WIDTH - 3 * INIT_GAP) / 2);
    glutDisplayFunc(renderSubwindow);

    plotComparisonWindow = glutCreateSubWindow(mainWindow,
                                               (INIT_WINDOW_WIDTH + INIT_GAP) / 2,
                                               INIT_GAP,
                                               (INIT_WINDOW_WIDTH - 3 * INIT_GAP) / 2,
                                               (INIT_WINDOW_WIDTH - 3 * INIT_GAP) / 2);
    glutDisplayFunc(renderSubwindow);

    sortSelectionWindow = glutCreateSubWindow(mainWindow,
                                              INIT_GAP,
                                              (INIT_WINDOW_WIDTH + INIT_GAP) / 2,
                                              INIT_WINDOW_WIDTH - 2 * INIT_GAP,
                                              (2 * INIT_WINDOW_HEIGHT - INIT_WINDOW_WIDTH - 3 * INIT_GAP) / 2);
    glutDisplayFunc(renderSubwindow);
}


void Application::renderBackground() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(32 / 255., 32 / 255., 32 / 255., 1.0);

    glutSwapBuffers();
}


void Application::renderSubwindow() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutSwapBuffers();
}


void Application::changeSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width, height);

    glMatrixMode(GL_MODELVIEW);
}
