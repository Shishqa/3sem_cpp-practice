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

        ScrollSlider* slider;
        ScrollButton* up_button;
        ScrollButton* down_button;

        FrameScrollable* target;

    public:

        Scrollbar(Window* parent, FrameScrollable* target,
                  const ScrollbarColorscheme& colors,
                  const Vector2<double>& size,
                  const Vector2<double>& pos = {0, 0});

        ~Scrollbar() override = default;

        /*--------------------------------------------------------------------*/

        double contentProportion();

        /*--------------------------------------------------------------------*/

        void reactOnButton(const MouseButtonEvent* event) override;

        /*--------------------------------------------------------------------*/

        void slide(double delta_in_pixels) override;

        double stepSize() override;

        double frameSize() override;

    protected:

        bool filterEvent(const Event* event) override;

        bool onMouseScroll(const MouseScrollEvent* event) override;

        bool unhandledEvent(const Event* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollSlider : public RectSlider {
    public:

        ScrollSlider(Window* parent, const ButtonColorScheme& colors,
                     const Vector2<double>& guide,
                     const Vector2<double>& size,
                     const Vector2<double>& pos = {0, 0});

        ~ScrollSlider() override = default;

    protected:

        bool onMouseMove(const MouseEvent* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollButton : public RectHoldableButton {
    protected:

        Mouse::ScrollDelta delta;

    public:

        ScrollButton(Window* parent, Mouse::ScrollDelta delta,
                     const ButtonColorScheme& colors,
                     const Vector2<double>& size,
                     const Vector2<double>& pos = {0, 0});

        ~ScrollButton() override = default;

        void setDelta(Mouse::ScrollDelta mouse_delta) {
            delta = mouse_delta;
        }

    protected:

        void reactOnButton(const MouseButtonEvent*) override {};

        void reactOnHold(const TimerEvent* event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
