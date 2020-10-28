/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/window_container.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowContainer::WindowContainer(Window* parent,
                                 const Vector2<int>& position)
                                 : Window(parent, position) {

    printf("Window %p is a container",
                        reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

bool WindowContainer::detach(Window* win_ptr) {
    return (0 != subwindows.erase(win_ptr));
}

/*----------------------------------------------------------------------------*/

bool WindowContainer::getEvent(const Event* event) {

    bool status = false;

    if (Window::getEvent(event)) {
        status = true;
    }

    for (auto& win : subwindows) {
        if (win->getEvent(event)) {
            status = true;
        }
    }

    return status;
}

/*============================================================================*/
