#include <GL/freeglut.h>
#include <GL/gl.h>

#include <algorithm>

#include "../include/application.hpp"
#include "../include/sorting_wrap.hpp"
#include "../include/sort_collection.hpp"


void onRender() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    draw();

    glutSwapBuffers();
}


void draw() {
    static const int    MIN_ARR_SIZE = 10,
                        MAX_ARR_SIZE = 100,
                        STEP         = 10;

    glPushMatrix();

    glScalef(1.0f / (MAX_ARR_SIZE - MIN_ARR_SIZE), 1.0f / 4900, 1.0f);
    glTranslatef(static_cast<float>(-MIN_ARR_SIZE), -45, 0.0);
    glColor3f(1.0, 0.0, 1.0);

    SortingWrap sortingWrap(std::sort);
    Stat stat = {};

    glBegin(GL_LINE_STRIP);
        for (size_t arr_size = MIN_ARR_SIZE; arr_size <= MAX_ARR_SIZE; arr_size += STEP) {

            stat = sortingWrap(arr_size);

            std::cout << arr_size << ";" << stat.compare_cnt << "\n";

            glVertex2f(static_cast<float>(arr_size), static_cast<float>(stat.compare_cnt));

        }
    glEnd();

    glPopMatrix();
}


void onReshape(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


void onIdle() {

    glutPostRedisplay();
}
