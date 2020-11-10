/*============================================================================*/
#ifndef SHISHGL_TIMER_EVENT_HPP
#define SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
#include "base_event.hpp"
/*============================================================================*/
namespace ShishGL {

    class TimerEvent : public Event {
    public:

        explicit TimerEvent(const TimeDelta& delta)
                : time_delta(delta) {}

        ~TimerEvent() override = default;

        [[nodiscard]]
        inline const TimeDelta& delta() const { return time_delta; }

        bool happen(Object::ID listener) override {
            return ObjectManager::get<Listener>(listener).onTimer(*this);
        }

    protected:

        TimeDelta time_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
