/*============================================================================*/
#include "ShishGL/event/event_buffer.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool EventBuffer::hasEvents() const {
    return !events.empty();
}

/*----------------------------------------------------------------------------*/

void EventBuffer::flush() {
    while (hasEvents()) {
        dispatchNextEvent();
    }
}

/*----------------------------------------------------------------------------*/

void EventBuffer::dispatchNextEvent() {
    if (!hasEvents()) {
        return;
    }

    const Event* event = events.front();
                         events.pop();

    /* TODO: normal event processing */

    delete event;
}

/*============================================================================*/
