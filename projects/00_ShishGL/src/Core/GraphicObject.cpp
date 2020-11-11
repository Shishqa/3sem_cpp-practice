/*============================================================================*/
#include "GraphicObject.hpp"
#include "SubscriptionManager.hpp"
#include "CoreApplication.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

GraphicObject::GraphicObject(Object::ID id)
    : Object(id) {
    SubscriptionManager::subscribe(CoreApplication::RENDER_EVENTS, Object::id());
}

/*----------------------------------------------------------------------------*/

bool RenderEvent::happen(Object::ID listener) {
    return GET<GraphicObject>(listener).onRender();
}

/*============================================================================*/
