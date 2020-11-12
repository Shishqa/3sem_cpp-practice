/*============================================================================*/
#include "SystemObject.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SystemObject::SystemObject(Object::ID id)
    : Object(id)
    { }

/*----------------------------------------------------------------------------*/

bool SystemObject::onMouseMove(class MouseEvent&) { return false; }
bool SystemObject::onMouseButton(class MouseButtonEvent&) { return false; }
bool SystemObject::onMouseScroll(class MouseScrollEvent&) { return false; }
bool SystemObject::onKeyboard(class KeyboardEvent&) { return false; }
bool SystemObject::onTimer(class TimerEvent&) { return false; }

/*============================================================================*/
