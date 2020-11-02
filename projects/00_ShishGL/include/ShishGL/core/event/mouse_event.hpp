/*============================================================================*/
#ifndef SHISHGL_MOUSE_EVENT_HPP
#define SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
#include "base_event.hpp"
#include "ShishGL/core/input/mouse.hpp"
#include "ShishGL/core/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class MouseEvent : public Event {
    public:

        MouseEvent(Event::Type type, const Vector2<double>& where)
            : Event(type)
            , m_where(where) {}

        ~MouseEvent() override = default;

        [[nodiscard]]
        const Vector2<double>& where() const { return m_where; }

        bool happen(Object* object) const override {
            return object->onMouseMove(this);
        }

    protected:

        Vector2<double> m_where;

    };

    /*------------------------------------------------------------------------*/

    class MouseButtonEvent : public MouseEvent {
    public:

        MouseButtonEvent(Event::Type type, const Vector2<double>& where,
                         Mouse::Button button, Mouse::ButtonState state)
            : MouseEvent(type, where)
            , m_button(button)
            , m_state(state) {}

        ~MouseButtonEvent() override = default;

        [[nodiscard]]
        inline Mouse::Button button() const { return m_button; }

        [[nodiscard]]
        inline Mouse::ButtonState state() const { return m_state; }

        bool happen(Object* object) const override {
            return object->onMouseClick(this);
        }

    protected:

        Mouse::Button m_button;
        Mouse::ButtonState m_state;

    };

    /*------------------------------------------------------------------------*/

    class MouseScrollEvent : public MouseEvent {
    public:

        MouseScrollEvent(Event::Type type, const Vector2<double>& where,
                         Mouse::ScrollDelta delta)
            : MouseEvent(type, where)
            , m_delta(delta) {

            if (m_delta > 1.0) {
                m_delta = 1.0;
            } else if (m_delta < -1.0) {
                m_delta = -1.0;
            }

        }

        ~MouseScrollEvent() override = default;

        [[nodiscard]]
        inline Mouse::ScrollDelta delta() const { return m_delta; }

        bool happen(Object* object) const override {
            object->onMouseScroll(this);
        }

    protected:

        Mouse::ScrollDelta m_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
