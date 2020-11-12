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

void SubscriptionManager::subscribe(Object::ID sender, Object::ID receiver) {
    Subscriptions()[sender].insert(receiver);
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribe(Object::ID sender, Object::ID receiver) {
    Subscriptions()[sender].erase(receiver);
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeAll(Object::ID sender) {
    Subscriptions()[sender].clear();
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeFromAll(Object::ID receiver) {
    for (auto& pool : Subscriptions()) {
        if (pool.second.count(receiver)) {
            pool.second.erase(receiver);
        }
    }
}

/*============================================================================*/