/*============================================================================*/
#ifndef SHISHGL_UI_SCROLLBAR_HPP
#define SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace ShishGL {

    class Scrollbar : public Clickable {
    protected:

        class Button;

        static constexpr double DEFAULT_PROPORTION = 0.2;
        static constexpr double DEFAULT_STEP_SIZE = 1.0;
        static constexpr double MIN_SLIDER_SIZE = 20;

    public:

        enum Type {
            VERTICAL,
            HORIZONTAL
        };

        explicit Scrollbar(UIWindow* target, const double& slider_ratio,
                           Scrollbar::Type type);

        void reactOnPress(MouseButtonEvent& event) override;

        UIWindow* inc_button;
        UIWindow* dec_button;
        UIWindow* slider;

    };

    /*------------------------------------------------------------------------*/

    class Scrollbar::Button : public Holdable {
    protected:

        Mouse::ScrollDelta m_delta;
        Mouse::ScrollType m_type;

    public:

        Button(UIWindow* target,
               Mouse::ScrollDelta delta,
               Mouse::ScrollType type)
               : Holdable(target)
               , m_delta(delta)
               , m_type(type)
               { }

        ~Button() override = default;

    protected:

        void reactOnPress(MouseButtonEvent& event) override {}

        void reactOnHold(TimerEvent& event) override {}

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
