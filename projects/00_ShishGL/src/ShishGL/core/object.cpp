/*============================================================================*/
#include "ShishGL/core/object.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool Object::getEvent(const Event* event) {
    switch (event->type) {

        case Event::MOUSE_CLICK:
            this->onMouseClick(event);
            break;

        case Event::MOUSE_SCROLL:
            this->onMouseScroll(event);
            break;

        case Event::MOUSE_MOVE:
            this->onMouseMove(event);
            break;

        case Event::KEYBOARD:
            this->onKeyboard(event);
            break;

        default:
            return false;
    }

    return true;
}

/*============================================================================*/
