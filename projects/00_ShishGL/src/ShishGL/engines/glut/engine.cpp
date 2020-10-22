/*============================================================================*/
#include <GL/freeglut.h>

#include "ShishGL/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int GlutEngine::canvas_id = 0;

/*----------------------------------------------------------------------------*/

void GlutEngine::initialize(int* argc_ptr, char** argv) {

    /* initializing glut */
    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    /* setting some specific glut options */
    setInitOptions();

    /* initializing canvas */
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(static_cast<int>(getDisplayWidth()),
                       static_cast<int>(getDisplayHeight()));

    /* TODO: user-defined window name */
    canvas_id = glutCreateWindow("glut engine");

    /* setting handlers for event processing */
    setHandlers();
}

/*----------------------------------------------------------------------------*/

void GlutEngine::setInitOptions() {
    /* do not close after quiting the loop */
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::terminate() {
}

/*============================================================================*/

uint8_t GlutEngine::enterMainLoop() {
    glutMainLoop();
    return 0;
}

/*============================================================================*/

size_t GlutEngine::getDisplayWidth() {
    return static_cast<size_t>(glutGet(GLUT_SCREEN_WIDTH));
}

size_t GlutEngine::getDisplayHeight() {
    return static_cast<size_t>(glutGet(GLUT_SCREEN_HEIGHT));
}

/*----------------------------------------------------------------------------*/

void GlutEngine::setHandlers() {
    glutDisplayFunc         (manageRender);
    glutMouseFunc           (manageMouse);
    glutKeyboardFunc        (manageKey);
    glutMotionFunc          (manageMotion);
    glutPassiveMotionFunc   (managePassiveMotion);
}

/*============================================================================*/
