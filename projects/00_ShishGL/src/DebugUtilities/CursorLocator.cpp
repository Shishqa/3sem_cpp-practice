/*============================================================================*/
#include "Rectangle.hpp"
#include "CursorLocator.hpp"
#include "ColorCollection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

CursorLocator::CursorLocator(Object::ID id, Object::ID parent)
    : Window<Rectangle>(id, parent, RED, Vector2<double>{10, 10})
    { }

/*----------------------------------------------------------------------------*/

bool CursorLocator::onMouseMove(MouseEvent& event) {

    Window::getShape().setCenter(event.where());
    return true;

}

/*============================================================================*/