/*============================================================================*/
#include "Log.hpp"
#include "EventSystem.hpp"
#include "SubscriptionManager.hpp"
#include "TimerEvent.hpp"
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

        if (!ObjectManager::get<Object>(sub).filterEvent(*event)) {
            continue;
        }

        if (event->happen(sub)) {
            status = true;
        }
    }

    return status;
}

/*----------------------------------------------------------------------------*/

void EventSystem::dispatchEvents() {

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

    //bool status = sendEvent(SystemEvents::SYSTEM, event);

    /*
    if (!status) {
        //LogSystem::printWarning("missed event %s", typeid(*event).name());
    }
     */

    delete event;
}

/*----------------------------------------------------------------------------*/

void EventSystem::flush() {

    const Event* event = nullptr;
    while (!Events().empty()) {

        event = Events().front();
                Events().pop();

        LogSystem::printWarning("Event %s deleted", typeid(*event).name());

        delete event;
    }

}

/*============================================================================*/
