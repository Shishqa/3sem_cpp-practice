#include "application.hpp"

#include <cstdio>

#include <GL/freeglut.h>
#include <GL/gl.h>


#include "sorting_wrap.hpp"
#include "../include/sorting_stat/sort_collection.hpp"


void onRender() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawGraph();

    glutSwapBuffers();
}


void drawGraph() {
    static const int    MIN_ARR_SIZE = 10,
                        MAX_ARR_SIZE = 100,
                        STEP         = 10;

    glPushMatrix();

    glScalef(1.0f / (MAX_ARR_SIZE - MIN_ARR_SIZE), 1.0f / 4900, 1.0f);
    glTranslatef(-static_cast<float>(MIN_ARR_SIZE), -45, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glLineWidth(2.0);

    SortingWrap sortingWrap(bubble_sort, fill_random);
    Stat stat = {};

    glBegin(GL_LINE_STRIP);
        for (size_t arr_size = MIN_ARR_SIZE; arr_size <= MAX_ARR_SIZE; arr_size += STEP) {

            stat = sortingWrap(arr_size);

            printf("%d;%d\n", stat.assign_cnt, stat.compare_cnt);

            glVertex2f(static_cast<float>(arr_size), static_cast<float>(stat.compare_cnt));

        }
    glEnd();

    glPopMatrix();
}


void onReshape(int width, int height) {

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

