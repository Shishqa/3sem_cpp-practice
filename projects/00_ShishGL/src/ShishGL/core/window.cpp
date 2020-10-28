/*============================================================================*/
#include "ShishGL/core/window.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event.hpp"
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

void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

bool Window::getEvent(const Event* event) {
    switch (event->type) {

        case Event::RENDER:
            this->onRender();
            return true;

        default:
            return Object::getEvent(event);

    }
}

/*============================================================================*/
