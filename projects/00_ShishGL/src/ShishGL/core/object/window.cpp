/*============================================================================*/
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event/base_event.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(Object::ID id, Object::ID parent)
        : Object(id)
        , parent(parent) {

    LogSystem::printLog("Created window %lu (parent=%lu)", id, parent);

}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    for (const auto& sub_win : subwindows) {
        ObjectManager::remove(sub_win);
    }
}

/*----------------------------------------------------------------------------*/

void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

bool Window::detach(Object::ID id) {
    return subwindows.erase(id);
}

/*----------------------------------------------------------------------------*/

bool Window::getEvent(const Event* event) {

    bool status = false;

    switch (event->type()) {

        case Event::RENDER:
            this->onRender();
            status = true;
            break;

        default:
            if (Object::getEvent(event)) {
                status = true;
            }

    }

    for (auto& win : subwindows) {
        if (EventSystem::sendEvent(win, event)) {
            status = true;
        }
    }

    return status;
}

/*============================================================================*/
