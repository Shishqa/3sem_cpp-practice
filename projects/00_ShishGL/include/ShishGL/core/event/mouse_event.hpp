/*============================================================================*/
#ifndef SHISHGL_MOUSE_EVENT_HPP
#define SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
#include "base_event.hpp"
#include "ShishGL/core/input/mouse.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class MouseEvent : public Event {
    public:

        explicit MouseEvent(const Vector2<double>& where)
            : m_where(where) {}

        ~MouseEvent() override = default;

        [[nodiscard]]
        const Vector2<double>& where() const { return m_where; }

        bool happen(Object::ID listener) override {
            return GET<Object>(listener).onMouseMove(*this);
        }

    protected:

        Vector2<double> m_where;

    };

    /*------------------------------------------------------------------------*/

    class MouseButtonEvent : public MouseEvent {
    public:

        MouseButtonEvent(const Vector2<double>& where,
                         Mouse::Button button,
                         Mouse::ButtonState state)
            : MouseEvent(where)
            , m_button(button)
            , m_state(state) {}

        ~MouseButtonEvent() override = default;

        [[nodiscard]]
        inline Mouse::Button button() const { return m_button; }

        [[nodiscard]]
        inline Mouse::ButtonState state() const { return m_state; }

        bool happen(Object::ID listener) override {
            return GET<Object>(listener).onMouseClick(*this);
        }

    protected:

        Mouse::Button m_button;
        Mouse::ButtonState m_state;

    };

    /*------------------------------------------------------------------------*/

    class MouseScrollEvent : public MouseEvent {
    public:

        MouseScrollEvent(const Vector2<double>& where,
                         Mouse::ScrollDelta delta)
            : MouseEvent(where)
            , m_delta(delta) {}

        ~MouseScrollEvent() override = default;

        [[nodiscard]]
        inline Mouse::ScrollDelta delta() const { return m_delta; }

        bool happen(Object::ID listener) override {
            return GET<Object>(listener).onMouseScroll(*this);
        }

    protected:

        Mouse::ScrollDelta m_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
