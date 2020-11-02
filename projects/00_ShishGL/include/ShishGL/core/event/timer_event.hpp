/*============================================================================*/
#ifndef SHISHGL_TIMER_EVENT_HPP
#define SHISHGL_TIMER_EVENT_HPP
/*============================================================================*/
namespace ShishGL {

    class TimerEvent : public Event {
    public:

        TimerEvent(Event::Type type, const TimeDelta& delta)
                : Event(type)
                , time_delta(delta) {}

        ~TimerEvent() override = default;

        [[nodiscard]]
        inline const TimeDelta& delta() const { return time_delta; }

        bool happen(Object* object) const override {
            object->onTimer(this);
        }

    protected:

        TimeDelta time_delta;

    };


}
/*============================================================================*/
#endif //SHISHGL_TIMER_EVENT
/*============================================================================*/