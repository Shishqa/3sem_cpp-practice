/*============================================================================*/
#include "TimerEvent.hpp"
#include "ObjectManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

TimerEvent::TimerEvent(const TimeDelta &delta)
        : time_delta(delta) { }

/*----------------------------------------------------------------------------*/

const TimeDelta& TimerEvent::delta() const {
    return time_delta;
}

/*----------------------------------------------------------------------------*/

bool TimerEvent::happen(Object::ID listener) {
    return GET<SystemObject>(listener).onTimer(*this);
}

/*============================================================================*/
