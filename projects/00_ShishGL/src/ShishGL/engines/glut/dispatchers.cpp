/*============================================================================*/
#include <GL/freeglut.h>
#include <cstdio>

#include "ShishGL/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void GlutEngine::manageRender() {
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageMouse(int button, int state, int x, int y) {
    if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state) {
        printf("clicked at (%d; %d)\n", x, y);
    }
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageMotion(int x, int y) {
}

/*----------------------------------------------------------------------------*/

void GlutEngine::managePassiveMotion(int x, int y) {
}

/*----------------------------------------------------------------------------*/

void GlutEngine::manageKey(unsigned char key, int x, int y) {
}

/*============================================================================*/
