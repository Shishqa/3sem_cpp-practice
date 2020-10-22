/*============================================================================*/
#include "ShishGL/log.hpp"
#include "ShishGL/window/window_container.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowContainer::WindowContainer(const Vector2<size_t>& size,
                                 const Vector2<int>& pos)
                                 : Window(size, pos) {

    LogSystem::printLog("Window %p is a container",
                        reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

bool WindowContainer::detach(Window* win_ptr) {
    return (0 != subwindows.erase(win_ptr));
}

/*----------------------------------------------------------------------------*/

/* TODO: */
bool WindowContainer::getEvent(const Event* event) {
    return true;
}

/*============================================================================*/
