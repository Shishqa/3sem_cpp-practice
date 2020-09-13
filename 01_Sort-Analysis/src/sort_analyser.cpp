
#include "sort_analyser.hpp"


SortAnalyser::SortAnalyser()
        : Application("Sort Analyser", 1024, 800) { }


void SortAnalyser::onRender() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutSwapBuffers();
}


void SortAnalyser::onReshape(int width, int height) {

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

}


void SortAnalyser::onMouseClick(int button, int state, int x, int y) {

    printf("clicked %d(%d) at (%d, %d)\n", button, state, x, y);

}


void SortAnalyser::onKeyPress(unsigned char key, int x, int y) {

    printf("pressed %c at (%d, %d)\n", key, x, y);

}
