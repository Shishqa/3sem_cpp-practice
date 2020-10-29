/*============================================================================*/
#include <GL/freeglut.h>

#include "ShishGL/core/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int GlutEngine::canvas_id = 0;

/*----------------------------------------------------------------------------*/

bool GlutEngine::initialize(int* argc_ptr, char** argv) {

    /* initializing glut */
    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    /* setting some specific glut options */
    setInitOptions();

    /* initializing "display" */
    glutInitWindowPosition(0, 0);

    Vector2<size_t> display_size = getDisplaySize();
    glutInitWindowSize(static_cast<int>(display_size.x),
                       static_cast<int>(display_size.y));

    /* TODO: defined window name */
    canvas_id = glutCreateWindow("glut engine");

    /* setting handlers for event processing */
    setHandlers();

    return true;
}

/*----------------------------------------------------------------------------*/

void GlutEngine::setInitOptions() {
    /* do not close after quiting the loop */
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

/*----------------------------------------------------------------------------*/

bool GlutEngine::terminate() {
    return true;
}

/*============================================================================*/

Vector2<size_t> GlutEngine::getDisplaySize() {
    return Vector2<size_t>{
        static_cast<size_t>(glutGet(GLUT_SCREEN_WIDTH)),
        static_cast<size_t>(glutGet(GLUT_SCREEN_HEIGHT))
    };
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
