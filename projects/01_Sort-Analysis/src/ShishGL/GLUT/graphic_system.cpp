
#include <GL/freeglut.h>

#include "ShishGL/GLUT/graphic_system.hpp"

using namespace ShishGL;


GlutSystem::WIN_ID
GlutSystem::create_window(const std::string_view& name,
                          Vector2<int> position,
                          Vector2<size_t> size) {

    glutInitWindowPosition(position.x, position.y);
    glutInitWindowSize(size.x, size.y);

    return glutCreateWindow(name.data());
}


GlutSystem::WIN_ID
GlutSystem::create_window(WIN_ID parent_id,
                          Vector2<int> position,
                          Vector2<size_t> size) {

    return glutCreateSubWindow(parent_id,
                               position.x, position.y,
                               size.x, size.y);
}


void GlutSystem::destroy_window(WIN_ID window_id) {
    glutDestroyWindow(window_id);
}


GlutSystem::EventQueue& GlutSystem::getEvents() {
    static EventQueue EVENTS;
    return EVENTS;
}


Event* GlutSystem::nextEvent() {

    if (getEvents().empty()) {

    }

}
