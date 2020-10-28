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

void EventSystem::pollEngine() {

    Event curr_event = {};
    if (!Engine::pollEvent(curr_event)) {
        return;
    }

    postEvent(curr_event);
}

/*----------------------------------------------------------------------------*/

bool EventSystem::dispatchEvents() {

    pollEngine();

    while (!Events().empty()) {
        if (!dispatchSingleEvent()) {
            return false;
        }
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool EventSystem::dispatchSingleEvent() {

    if (Events().empty()) {
        return true;
    }

    const Event* event = Events().front();
                         Events().pop();

    bool status = (event->type != Event::TERMINATE);

    if (!CoreApplication::Root().getEvent(event)) {
        LogSystem::printWarning("missed event {type=%d}", event->type);
    }

    delete event;

    return status;
}

/*============================================================================*/
