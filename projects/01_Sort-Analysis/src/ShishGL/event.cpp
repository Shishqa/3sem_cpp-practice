#include "ShishGL/ShishGL.hpp"

using namespace ShishGL;


std::queue<Event> EventSystem::events;


void EventSystem::addEvent(const Event& event) {
    events.emplace(event);
}


void EventSystem::processNewEvents() {

    while (!events.empty()) {

        Event curr_event = events.front();

        if (!curr_event.target) {
            printLog("Warning: event with empty target passed!");
        } else {
            printLog("Target: %p, code: %d", reinterpret_cast<void*>(curr_event.target),
                                             curr_event.event_code);
            curr_event.target->getEvent(curr_event);
        }

        events.pop();
    }
}
