/*============================================================================*/
#include "ShishGL/graphics/window/button.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool Button::filterEvent(const Event* event) {

    if (num_pressed) {
        return true;
    }

    if (event->type() == Event::MOUSE_BUTTON) {

        auto mouse = dynamic_cast<const MouseEvent*>(event);
        if (!mouse) {
            return false;
        }

        if (!contains(mouse->where())) {
            return false;
        }
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool Button::onMouseClick(const MouseButtonEvent* event) {

    if (event->state() == Mouse::DOWN) {

        num_pressed++;
        reactOnButton(event);

    } else if (num_pressed) {

        num_pressed--;
        reactOnButton(event);

    }
    return true;
}

/*----------------------------------------------------------------------------*/

bool Button::onTimer(const TimerEvent* event) {
    if (num_pressed) {
        reactOnHold(event);
        return true;
    }
    return false;
}

/*============================================================================*/
