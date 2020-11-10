/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event_system.hpp"
#include "ShishGL/core/subscription_manager.hpp"
#include "ShishGL/core/core_application.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

EventSystem::EventQueue& EventSystem::Events() {
    static EventQueue EVENTS;
    return EVENTS;
}

/*----------------------------------------------------------------------------*/

SubscriptionManager::SubscriptionPool& SubscriptionManager::Subscriptions() {
    static SubscriptionPool POOL;
    return POOL;
}

/*----------------------------------------------------------------------------*/

Timer& EventSystem::EventTimer() {
    static Timer EVENT_TIMER;
    return EVENT_TIMER;
}

/*============================================================================*/

bool EventSystem::sendEvent(Object::ID sender, Event* event) {

    bool status = false;

    for (auto& sub : SubscriptionManager::Subscriptions()[sender]) {

        if (!ObjectManager::get<Listener>(sub).filterEvent(*event)) {
            continue;
        }

        if (event->happen(sub)) {
            status = true;
        }
    }

    return status;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::subscribe(Object::ID sender, Object::ID receiver) {
    Subscriptions()[sender].insert(receiver);
}

void SubscriptionManager::unsubscribe(Object::ID sender, Object::ID receiver) {
    Subscriptions()[sender].erase(receiver);
}

void SubscriptionManager::unsubscribeAll(Object::ID sender) {
    Subscriptions()[sender].clear();
}

/*----------------------------------------------------------------------------*/

bool EventSystem::pollEngine() {

    auto event = Engine::pollEvent();
    if (!event) {
        return false;
    }

    Events().emplace(event);
    return true;
}

/*----------------------------------------------------------------------------*/

void EventSystem::dispatchEvents() {

    pollEngine();

    if (!Engine::isRunning()) {
        return;
    }

    while (!Events().empty()) {
        dispatchSingleEvent();
    }

    TimeDelta elapsed = EventTimer().elapsed();
    if (elapsed.count() > 55000000) { /* todo: fix hardcoded 55ms */

        postEvent<TimerEvent>(elapsed);
        EventTimer().reset();

    }
}

/*----------------------------------------------------------------------------*/

void EventSystem::dispatchSingleEvent() {

    if (Events().empty()) {
        return;
    }

    Event* event = Events().front();
    Events().pop();

    bool status = sendEvent(SystemEvents::SYSTEM, event);

    if (!status) {
        //LogSystem::printWarning("missed event %s", typeid(*event).name());
    }

    delete event;
}

/*----------------------------------------------------------------------------*/

void EventSystem::flush() {

    const Event* event = nullptr;
    while (!Events().empty()) {

        event = Events().front();
                Events().pop();

        LogSystem::printLog("Event %s deleted", typeid(*event).name());

        delete event;
    }

}

/*============================================================================*/
