/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/event_system.hpp"
#include "ShishGL/core/core_application.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

EventSystem::EventQueue& EventSystem::Events() {
    static EventQueue EVENTS;
    return EVENTS;
}

/*----------------------------------------------------------------------------*/

Timer& EventSystem::EventTimer() {
    static Timer EVENT_TIMER;
    return EVENT_TIMER;
}

/*============================================================================*/

bool EventSystem::sendEvent(Object* object, const Event* event) {
    return (object->filterEvent(event) && object->getEvent(event));
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

        postEvent<TimerEvent>(Event::TIMER, elapsed);
        EventTimer().reset();

    }
}

/*----------------------------------------------------------------------------*/

void EventSystem::dispatchSingleEvent() {

    if (Events().empty()) {
        return;
    }

    const Event* event = Events().front();
                         Events().pop();

    bool status = false;
    for (const auto& obj : CoreApplication::ActiveObjects()) {
        if (obj->filterEvent(event) && obj->getEvent(event)) {
            status = true;
        }
    }

    if (!status) {
        //LogSystem::printWarning("missed event {type=%d}", event->type());
    }

    delete event;
}

/*----------------------------------------------------------------------------*/

void EventSystem::flush() {

    const Event* event = nullptr;
    while (!Events().empty()) {

        event = Events().front();
                Events().pop();

        delete event;
    }

}

/*============================================================================*/
