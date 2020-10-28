/*============================================================================*/
#include "ShishGL/core/window.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(Window* parent, const Vector2<int>& pos)
               : parent(parent)
               , rel_pos(pos)
               , abs_pos(rel_pos) {

    Window* curr_win = parent;
    while (curr_win) {
        abs_pos += curr_win->rel_pos;
        curr_win = curr_win->parent;
    }

    printf("Created window %p at (%d, %d) {%d, %d} (parent=%p)\n",
                        reinterpret_cast<void*>(this),
                        rel_pos.x, rel_pos.y, abs_pos.x, abs_pos.y,
                        reinterpret_cast<void*>(parent));
    fflush(stdout);
}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    LogSystem::printLog("Window %p destroyed",
                        reinterpret_cast<void*>(this));
}

/*----------------------------------------------------------------------------*/

const Vector2<int>& Window::getRelPos() const {
    return rel_pos;
}

/*----------------------------------------------------------------------------*/

const Vector2<int>& Window::getAbsPos() const {
    return abs_pos;
}

/*----------------------------------------------------------------------------*/

//TODO: set window before redrawing
void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

bool Window::getEvent(const Event* event) {
    switch (event->type) {

        case Event::RENDER:
            this->onRender();
            return true;

        case Event::MOUSE_CLICK:
        case Event::MOUSE_HOVER:
        case Event::MOUSE_MOVE:
            this->onMouse(&event->mouse);
            return true;

        case Event::KEY_PRESS:
            this->onKeyboard(&event->keyboard);
            return true;

        case Event::IDLE:
            this->onIdle(&event->timer);
            return true;

        default:
            return false;

    }
}

/*============================================================================*/
