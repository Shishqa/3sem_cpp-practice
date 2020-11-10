/*============================================================================*/
#ifndef SHISHGL_SCROLLBAR_HPP
#define SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
#include "ShishGL/ables/scrollable.hpp"
#include "ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    /*========================================================================*/
    struct ScrollbarColorscheme {
        ButtonColorScheme bg;
        ButtonColorScheme slider;
        ButtonColorScheme button;
    };
    /*------------------------------------------------------------------------*/
    static constexpr ScrollbarColorscheme DEFAULT_SCROLLBAR_COLORS = {
            {DARK_SLATE_GREY, DARK_SLATE_GREY, DARK_SLATE_GRAY},
            {PAPAYA_WHIP, LIGHT_SLATE_GRAY, WHITE},
            {DARK_SEA_GREEN, LIGHT_SLATE_GRAY, WHITE}
    };
    /*========================================================================*/

    class ScrollSlider;

    class ScrollButton;

    /*------------------------------------------------------------------------*/

    class Scrollbar : public RectButton, public FrameScrollable {
    protected:

        static constexpr double DEFAULT_PROPORTION = 0.2;
        static constexpr double DEFAULT_STEP_SIZE = 1.0;

        static constexpr double MIN_SLIDER_SIZE = 20;

        Object::ID slider;
        Object::ID up_button;
        Object::ID down_button;

        FrameScrollable* target;

    public:

        Scrollbar(Object::ID id, Object::ID parent, FrameScrollable* target,
                  const ScrollbarColorscheme& colors,
                  const Vector2<double>& size,
                  const Vector2<double>& pos = {0, 0});

        ~Scrollbar() override = default;

        /*--------------------------------------------------------------------*/

        double contentProportion() const;

        /*--------------------------------------------------------------------*/

        void reactOnButton(MouseButtonEvent& event) override;

        /*--------------------------------------------------------------------*/

        void slide(double delta_in_pixels) override;

        double stepSize() const override;

        double limitSize() const  override;

        double frameSize() const override;

    protected:

        bool filterEvent(Event& event) const override;

        bool onMouseScroll(MouseScrollEvent& event) override;

        bool onSlide(Event& event);

    };

    /*------------------------------------------------------------------------*/

    class ScrollSlider : public RectSlider {
    public:

        ScrollSlider(Object::ID id, Object::ID parent, const ButtonColorScheme& colors,
                     const Vector2<double>& guide,
                     const Vector2<double>& size,
                     const Vector2<double>& pos = {0, 0});

        ~ScrollSlider() override = default;

    protected:

        bool onMouseMove(MouseEvent& event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollButton : public RectHoldableButton {
    protected:

        Mouse::ScrollDelta delta;

    public:

        ScrollButton(Object::ID id, Object::ID parent,
                     Mouse::ScrollDelta delta,
                     const ButtonColorScheme& colors,
                     const Vector2<double>& size,
                     const Vector2<double>& pos = {0, 0});

        ~ScrollButton() override = default;

        void setDelta(Mouse::ScrollDelta mouse_delta) {
            delta = mouse_delta;
        }

    protected:

        void reactOnHold(TimerEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
