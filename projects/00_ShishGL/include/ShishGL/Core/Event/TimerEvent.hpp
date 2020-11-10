/*============================================================================*/
#ifndef SHISHGL_TIMER_EVENT_HPP
#define SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
#include "Event.hpp"
#include "Time.hpp"
#include "ObjectManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class TimerEvent : public Event {
    public:

        explicit TimerEvent(const TimeDelta& delta);

        ~TimerEvent() override = default;

        [[nodiscard]]
        inline const TimeDelta& delta() const;

        bool happen(Object::ID listener) override;

    protected:

        TimeDelta time_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
