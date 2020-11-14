/*============================================================================*/
#include "LogSystem.hpp"
#include "Listener.hpp"
#include "EventManager.hpp"
#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool EventSystem::sendEvent(Listener* sender, Event& event) {

    bool status = false;

    for (auto& sub : SubscriptionManager::Subscriptions()[sender]) {
        if (sub->filterEvent(event) && event.happen(sub)) {
            status = true;
        }
    }

    return status;

}

/*----------------------------------------------------------------------------*/

bool EventSystem::dispatchAll() {

    bool status = false;

    while (!EventManager::Events().empty()) {
        if (dispatchOne()) {
            status = true;
        }
    }

    return status;
}

/*----------------------------------------------------------------------------*/

bool EventSystem::dispatchOne() {

    if (EventManager::Events().empty()) {
        return false;
    }

    Event* event = EventManager::Events().front();
    EventManager::Events().pop();

    bool status = sendEvent(SystemEvents, *event);
    if (!status && !SubscriptionManager::Subscriptions()[SystemEvents].empty()) {
        LogSystem::printWarning("Missed event %s", typeid(*event).name());
    }

    delete event;
    return status;
}

/*============================================================================*/