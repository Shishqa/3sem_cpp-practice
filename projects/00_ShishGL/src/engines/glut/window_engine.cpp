/*============================================================================*/

#include <GL/freeglut.h>

#include "engines/glut/window_engine.hpp"

using namespace ShishGL;

/*============================================================================*/

void GlutWindowEngine::init(int* argc_ptr, char** argv) {
    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

/*----------------------------------------------------------------------------*/

void GlutWindowEngine::enterMainLoop() {
    glutMainLoop();
}

/*----------------------------------------------------------------------------*/

GlutWindowEngine::WIN_ID
GlutWindowEngine::createWindow(const std::string_view& name,
                               const Vector2<int>& position,
                               const Vector2<size_t>& size) {

    glutInitWindowPosition(position.x, position.y);
    glutInitWindowSize(static_cast<int>(size.x),
                       static_cast<int>(size.y));

    WIN_ID id = glutCreateWindow(name.data());

    setHandlers();

    return id;
}

/*----------------------------------------------------------------------------*/

GlutWindowEngine::WIN_ID
GlutWindowEngine::createWindow(const WIN_ID& parent_id,
                               const Vector2<int>& position,
                               const Vector2<size_t>& size) {

    WIN_ID id = glutCreateSubWindow(parent_id,
                                    position.x, position.y,
                                    static_cast<int>(size.x),
                                    static_cast<int>(size.y));

    setHandlers();

    return id;
}

/*----------------------------------------------------------------------------*/

void GlutWindowEngine::setHandlers() {
    glutDisplayFunc(manageRender);
    glutIdleFunc(manageIdle);
    glutMouseFunc(manageMouse);
    glutKeyboardFunc(manageKey);
    glutMotionFunc(manageMotion);
    glutPassiveMotionFunc(managePassiveMotion);
    glutEntryFunc(manageEntry);
    glutReshapeFunc(manageReshape);
}

/*----------------------------------------------------------------------------*/

void GlutWindowEngine::destroyWindow(const WIN_ID& window_id) {
    glutDestroyWindow(window_id);
}

/*============================================================================*/
