/*============================================================================*/
#include "Object.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Object::Object(Object::ID id)
        : m_id(id)
        { }

/*----------------------------------------------------------------------------*/

Object::ID Object::id() const {
    return m_id;
}

/*----------------------------------------------------------------------------*/

bool Object::filterEvent(class Event &) const { return true; }

/*----------------------------------------------------------------------------*/

bool Object::unhandledEvent(class Event &) { return false; }
bool Object::onMouseMove(class MouseEvent &) { return false; }
bool Object::onMouseClick(class MouseButtonEvent &) { return false; }
bool Object::onMouseScroll(class MouseScrollEvent &) { return false; }
bool Object::onKeyboard(class KeyboardEvent &) { return false; }
bool Object::onTimer(class TimerEvent &) { return false; }

/*============================================================================*/
