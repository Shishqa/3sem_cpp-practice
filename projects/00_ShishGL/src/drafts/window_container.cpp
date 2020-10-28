/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "drafts/window_container.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowContainer::WindowContainer(Window* parent)
        : Window(parent) {

    LogSystem::printLog("Window %p is a container",
                        reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

WindowContainer::~WindowContainer() {
    for (const auto& win : subwindows) {
        delete win;
    }
}

/*----------------------------------------------------------------------------*/

Window* WindowContainer::detach(Window* win_ptr) {

    return (subwindows.erase(win_ptr) ? win_ptr : nullptr);
}

/*----------------------------------------------------------------------------*/

bool WindowContainer::getEvent(const Event* event) {

    bool status = false;

    if (this->filterEvent(event) && Window::getEvent(event)) {
        status = true;
    }

    for (auto& win : subwindows) {
        if (win->filterEvent(event) && win->getEvent(event)) {
            status = true;
        }
    }

    return status;
}

/*============================================================================*/
