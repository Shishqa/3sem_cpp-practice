/*============================================================================*/
#include "ShishGL/core/object.hpp"
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

#define CHECK_EVENT( SomeEventClass, event, handler ) {          \
    auto converted = dynamic_cast<const SomeEventClass*>(event); \
    return (converted ? this->handler(converted) : false);       \
}

/*----------------------------------------------------------------------------*/

bool Object::getEvent(const Event* event) {
    switch (event->type()) {

        case Event::MOUSE_BUTTON: CHECK_EVENT(MouseButtonEvent, event, onMouseClick)
        case Event::MOUSE_SCROLL: CHECK_EVENT(MouseScrollEvent, event, onMouseScroll)
        case Event::MOUSE_MOVE:   CHECK_EVENT(MouseEvent,       event, onMouseMove)
        case Event::KBD_BUTTON:   CHECK_EVENT(KeyboardEvent,    event, onKeyboard)
        case Event::TIMER:        CHECK_EVENT(TimerEvent,       event, onTimer)
        case Event::IDLE:         CHECK_EVENT(TimerEvent,       event, onIdle)

        default: break;
    }

    return unhandledEvent(event);
}

/*----------------------------------------------------------------------------*/

bool Object::filterEvent(const Event*) { return true; }

bool Object::onMouseMove(const MouseEvent*) { return false; }

bool Object::onMouseScroll(const MouseScrollEvent*) { return false; }

bool Object::onMouseClick(const MouseButtonEvent*) { return false; }

bool Object::onKeyboard(const KeyboardEvent*) { return false; }

bool Object::onTimer(const TimerEvent*) { return false; }

bool Object::onIdle(const TimerEvent*) { return false; }

bool Object::unhandledEvent(const Event*) { return false; }

/*============================================================================*/
