/*============================================================================*/
#include "ShishGL/core/object/object.hpp"
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool Object::getEvent(const Event* event) {
    switch (event->type()) {

        // TODO: macros

        case Event::MOUSE_BUTTON: {
            auto converted = dynamic_cast<const MouseButtonEvent*>(event);
            if (!converted) {
                return false;
            }
            return this->onMouseClick(converted);
        }

        case Event::MOUSE_SCROLL: {
            auto converted = dynamic_cast<const MouseScrollEvent*>(event);
            if (!converted) {
                return false;
            }
            return this->onMouseScroll(converted);
        }

        case Event::MOUSE_MOVE: {
            auto converted = dynamic_cast<const MouseEvent*>(event);
            if (!converted) {
                return false;
            }
            return this->onMouseMove(converted);
        }

       case Event::KBD_BUTTON: {
           auto converted = dynamic_cast<const KeyboardEvent *>(event);
           if (!converted) {
               return false;
           }
           return this->onKeyboard(converted);
       }

       default:
           break;
    }

    return false;
}

/*----------------------------------------------------------------------------*/

bool Object::filterEvent(const Event*) { return true; }

bool Object::onMouseMove(const MouseEvent*) { return false; }

bool Object::onMouseScroll(const MouseScrollEvent*) { return false; }

bool Object::onMouseClick(const MouseButtonEvent*) { return false; }

bool Object::onKeyboard(const KeyboardEvent*) { return false; }

/*============================================================================*/
