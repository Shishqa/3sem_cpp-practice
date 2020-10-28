/*============================================================================*/
#include "ShishGL/core/object.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool Object::getEvent(const Event* event) {
    switch (event->type) {

        case Event::MOUSE_CLICK:
        case Event::MOUSE_SCROLL:
        case Event::MOUSE_MOVE:
            this->onMouse(event);
            return true;

        case Event::KEYBOARD:
            this->onKeyboard(event);
            return true;

        default:
            return false;
    }
}

/*============================================================================*/
