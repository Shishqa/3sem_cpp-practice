/*============================================================================*/
#ifndef SHISHGL_MOUSE_EVENT_HPP
#define SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
#include "Event.hpp"
#include "Mouse.hpp"
#include "Vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class MouseEvent : public Event {
    public:

        explicit MouseEvent(const Vector2<double>& where);

        ~MouseEvent() override = default;

        [[nodiscard]]
        const Vector2<double>& where() const;

        bool happen(Object::ID listener) override;

    protected:

        Vector2<double> m_where;

    };

    /*------------------------------------------------------------------------*/

    class MouseButtonEvent : public MouseEvent {
    public:

        MouseButtonEvent(const Vector2<double>& where,
                         Mouse::Button button,
                         Mouse::ButtonState state);

        ~MouseButtonEvent() override = default;

        [[nodiscard]]
        inline Mouse::Button button() const;

        [[nodiscard]]
        inline Mouse::ButtonState state() const;

        bool happen(Object::ID listener) override;

    protected:

        Mouse::Button m_button;
        Mouse::ButtonState m_state;

    };

    /*------------------------------------------------------------------------*/

    class MouseScrollEvent : public MouseEvent {
    public:

        MouseScrollEvent(const Vector2<double>& where,
                         Mouse::ScrollDelta delta);

        ~MouseScrollEvent() override = default;

        [[nodiscard]]
        inline Mouse::ScrollDelta delta() const;

        bool happen(Object::ID listener) override;

    protected:

        Mouse::ScrollDelta m_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
