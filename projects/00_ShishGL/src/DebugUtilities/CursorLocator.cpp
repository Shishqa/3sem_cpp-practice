/*============================================================================*/
#include "CursorLocator.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

CursorLocator::CursorLocator(Object::ID id, Object::ID shape, Object::ID parent)
    : Window(id, shape, parent)
    { }

/*----------------------------------------------------------------------------*/

bool CursorLocator::onMouseMove(MouseEvent& event) {

    viewport.pos = event.where();
    Window::getShape().setPos(event.where());
    return true;

}

/*============================================================================*/