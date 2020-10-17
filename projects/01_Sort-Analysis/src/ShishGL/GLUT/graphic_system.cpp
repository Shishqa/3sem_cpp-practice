
#include <GL/freeglut.h>

#include "ShishGL/GLUT/graphic_system.hpp"

using namespace ShishGL;


void GlutSystem::init(int* argc_ptr, char** argv) {

    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

}


void GlutSystem::enterMainLoop() {
    glutMainLoop();
}


GlutSystem::WIN_ID
GlutSystem::createWindow(const std::string_view& name,
                          Vector2<int> position,
                          Vector2<size_t> size) {

    glutInitWindowPosition(position.x, position.y);
    glutInitWindowSize(static_cast<int>(size.x),
                       static_cast<int>(size.y));

    WIN_ID id = glutCreateWindow(name.data());

    glutDisplayFunc(manageOnRender);

    return id;
}


GlutSystem::WIN_ID
GlutSystem::createWindow(WIN_ID parent_id,
                          Vector2<int> position,
                          Vector2<size_t> size) {

    return glutCreateSubWindow(parent_id,
                               position.x, position.y,
                               static_cast<int>(size.x),
                               static_cast<int>(size.y));
}


void GlutSystem::destroyWindow(WIN_ID window_id) {
    glutDestroyWindow(window_id);
}


//GlutSystem::EventQueue& GlutSystem::getEvents() {
//    static EventQueue EVENTS;
//    return EVENTS;
//}
//
//
//Event* GlutSystem::nextEvent() {
//
//    if (getEvents().empty()) {
//
//    }
//
//}
