/*============================================================================*/
#include <GL/freeglut.h>
#include <cstdio>

#include "ShishGL/core/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Event* GlutEngine::pollEvent() {
    return nullptr;
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageRender() {
    printf("GLUT:: render!");
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageMouse(int button, int state, int x, int y) {
    if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state) {
        printf("GLUT:: clicked at (%d; %d)\n", x, y);
    }
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageMotion(int x, int y) {
    printf("GLUT:: moved mouse at (%d; %d)\n", x, y);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::managePassiveMotion(int x, int y) {
    printf("GLUT:: passive moved at (%d; %d)\n", x, y);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageKey(unsigned char key, int x, int y) {
    printf("GLUT:: pressed key %u at (%d; %d)\n", key, x, y);
}

/*============================================================================*/
