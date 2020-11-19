/*============================================================================*/
#include "MouseEvent.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

MouseEvent::MouseEvent(const Vector2<double> &where)
        : m_where(where)
        { }

/*----------------------------------------------------------------------------*/

const Vector2<double>& MouseEvent::where() const {
    return m_where;
}

/*----------------------------------------------------------------------------*/

void MouseEvent::setWhere(const Vector2<double>& pos) {
    m_where = pos;
}

/*----------------------------------------------------------------------------*/

bool MouseEvent::happen(Listener* listener) {
    return dynamic_cast<PlatformListener*>(listener)->onMouseMove(*this);
}

/*============================================================================*/

MouseButtonEvent::MouseButtonEvent(const Vector2<double>& where,
                                   Mouse::Button button,
                                   Mouse::ButtonState state)
                                   : MouseEvent(where)
                                   , m_button(button)
                                   , m_state(state)
                                   { }

/*----------------------------------------------------------------------------*/

Mouse::Button MouseButtonEvent::button() const {
    return m_button;
}

/*----------------------------------------------------------------------------*/

Mouse::ButtonState MouseButtonEvent::state() const {
    return m_state;
}

/*----------------------------------------------------------------------------*/

bool MouseButtonEvent::happen(Listener* listener) {
    return dynamic_cast<PlatformListener*>(listener)->onMouseButton(*this);
}

/*============================================================================*/

MouseScrollEvent::MouseScrollEvent(const Vector2<double>& where,
                                   Mouse::ScrollDelta delta)
                                   : MouseEvent(where)
                                   , m_delta(delta)
                                   { }

/*----------------------------------------------------------------------------*/

Mouse::ScrollDelta MouseScrollEvent::delta() const {
    return m_delta;
}

/*----------------------------------------------------------------------------*/

bool MouseScrollEvent::happen(Listener* listener) {
    return dynamic_cast<PlatformListener*>(listener)->onMouseScroll(*this);
}

/*============================================================================*/
