/*============================================================================*/
#include "CursorLocator.hpp"
#include "ColorCollection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

CursorLocator::CursorLocator(Shape2D* shape)
    : Window(shape)
    {
    SubscriptionManager::subscribe(EventSystem::SystemEvents, this);
    }

/*----------------------------------------------------------------------------*/

bool CursorLocator::onMouseMove(MouseEvent& event) {

    setPos(event.where());
    return true;

}

/*============================================================================*/