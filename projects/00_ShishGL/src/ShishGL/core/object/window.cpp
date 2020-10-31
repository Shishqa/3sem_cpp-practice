/*============================================================================*/
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event/base_event.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(Window* parent)
        : parent(parent) {

    LogSystem::printLog("Created window %p (parent=%p)",
                        reinterpret_cast<void*>(this),
                        reinterpret_cast<void*>(parent));

}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    for (const auto& sub_win : subwindows) {
        delete sub_win;
    }
}

/*----------------------------------------------------------------------------*/

void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

Window* Window::detach(Window* win_ptr) {
    return (subwindows.erase(win_ptr) ? win_ptr : nullptr);
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
