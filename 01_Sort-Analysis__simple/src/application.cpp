#include <cstdio>
#include <algorithm>
#include <set>

#include <GL/freeglut.h>
#include <GL/gl.h>

#include "application.hpp"

namespace Sorts {

    static SortGraph bubble = SortGraph(SortingWrap(bubble_sort, fill_random), {1.0, 0.0, 1.0, 1.0}),
                     merge = SortGraph(SortingWrap(merge_sort, fill_random), {1.0, 1.0, 0.0, 1.0}),
                     std_sort = SortGraph(SortingWrap(std::sort, fill_random), {1.0, 0.0, 0.0, 1.0});

    static std::set<SortGraph*> active_sorts;

};


void processMenu(int option) {

    switch (option) {

        case CLEAR:
            Sorts::active_sorts.clear();
            glutPostRedisplay();
            break;

        case BUBBLE_SORT:
            Sorts::active_sorts.insert(&Sorts::bubble);
            glutPostRedisplay();
            break;

        case MERGE_SORT:
            Sorts::active_sorts.insert(&Sorts::merge);
            glutPostRedisplay();
            break;

        case STD_SORT:
            Sorts::active_sorts.insert(&Sorts::std_sort);
            glutPostRedisplay();
            break;

        default:
            throw std::runtime_error("Error: unknown sort chosen!\n");
            break;
    }

}


void onRender() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (auto& sort_graph : Sorts::active_sorts) {
        drawGraph(*sort_graph);
    }

    glutSwapBuffers();
}


void drawGraph(SortGraph& graph) {

    static const int    MIN_ARR_SIZE = 10,
                        MAX_ARR_SIZE = 100,
                        STEP         = 5;

    graph.fill(MIN_ARR_SIZE, MAX_ARR_SIZE, STEP);

    glPushMatrix();

    glScalef(1.0f / (MAX_ARR_SIZE - MIN_ARR_SIZE) / 3, 1.0f / 10000, 1.0f);
    glTranslatef(-static_cast<float>(MIN_ARR_SIZE), 0.0f, 0.0f);
    glColor3d(graph.line_color.r, graph.line_color.g, graph.line_color.b);
    glLineWidth(2.0);

    Stat stat = {};

    glBegin(GL_LINE_STRIP);
        for (size_t arr_size = MIN_ARR_SIZE; arr_size <= MAX_ARR_SIZE; arr_size += STEP) {

            stat = graph[arr_size];

            glVertex2d(static_cast<double>(arr_size), static_cast<double>(stat.compare_cnt));

        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for (size_t arr_size = MIN_ARR_SIZE; arr_size <= MAX_ARR_SIZE; arr_size += STEP) {

            stat = graph[arr_size];

            glVertex2d(static_cast<double>(arr_size + MAX_ARR_SIZE), static_cast<double>(stat.assign_cnt));

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

