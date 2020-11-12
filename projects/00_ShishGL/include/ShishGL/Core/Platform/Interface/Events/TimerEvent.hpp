/*============================================================================*/
#ifndef SHISHGL_TIMER_EVENT_HPP
#define SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
#include "Time.hpp"
#include "Event.hpp"
#include "PlatformListener.hpp"
/*============================================================================*/
namespace ShishGL {

    class TimerEvent : public Event {
    public:

        explicit TimerEvent(const TimeDelta& delta);

        ~TimerEvent() override = default;

        [[nodiscard]]
        inline const TimeDelta& delta() const;

        bool happen(PlatformListener::ID listener) override;

    protected:

        TimeDelta time_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
