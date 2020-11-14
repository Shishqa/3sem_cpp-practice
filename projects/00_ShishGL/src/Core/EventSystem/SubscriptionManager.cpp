/*============================================================================*/
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SubscriptionManager::SubscriptionPool& SubscriptionManager::Subscriptions() {
    static SubscriptionPool POOL;
    return POOL;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::subscribe(Listener* sender, Listener* receiver) {
    Subscriptions()[sender].insert(receiver);
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribe(Listener* sender, Listener* receiver) {
    Subscriptions()[sender].erase(receiver);
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeAll(Listener* sender) {
    Subscriptions()[sender].clear();
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeFromAll(Listener* receiver) {
    for (auto& pool : Subscriptions()) {
        pool.second.erase(receiver);
    }
}

/*============================================================================*/