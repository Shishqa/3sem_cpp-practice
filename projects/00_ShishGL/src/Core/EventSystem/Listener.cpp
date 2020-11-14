/*============================================================================*/
#include "Listener.hpp"
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Listener::~Listener() {
    SubscriptionManager::unsubscribeAll(this);
    SubscriptionManager::unsubscribeFromAll(this);
}

/*----------------------------------------------------------------------------*/

bool Listener::filterEvent(Event&) const {
    return true;
}

/*----------------------------------------------------------------------------*/

bool Listener::onEvent(Event&) {
    return false;
}

/*============================================================================*/
