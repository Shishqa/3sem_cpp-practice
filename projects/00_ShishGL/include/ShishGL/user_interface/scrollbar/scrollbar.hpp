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
        Color bg;
        ButtonColorScheme slider;
        ButtonColorScheme button;
    };
    /*------------------------------------------------------------------------*/
    static constexpr ScrollbarColorscheme DEFAULT_SCROLLBAR_COLORS = {
            DARK_SLATE_GREY,
            {PAPAYA_WHIP, LIGHT_SLATE_GRAY, WHITE},
            {DARK_SEA_GREEN, LIGHT_SLATE_GRAY, WHITE}
    };
    /*========================================================================*/

    class ScrollSlider;

    class ScrollButton;

    /*------------------------------------------------------------------------*/

    class Scrollbar : public RectWindow, public FrameScrollable {
    protected:

        static constexpr double DEFAULT_PROPORTION = 0.2;
        static constexpr double DEFAULT_STEP_SIZE = 1.0;

        ScrollSlider* slider;
        FrameScrollable* target;

    public:

        Scrollbar(Window* parent, FrameScrollable* target,
                  const ScrollbarColorscheme& colors,
                  const Vector2<int>& pos,
                  const Vector2<size_t>& size);

        ~Scrollbar() override = default;

        double contentProportion();

        /*--------------------------------------------------------------------*/

        void slide(int delta) override;

        size_t stepSize() override;

        size_t getFrameSize() override;

        size_t getContentSize() override;

    protected:

        bool filterEvent(const Event* event) override;

        bool onMouseScroll(const MouseScrollEvent* event) override;

        bool unhandledEvent(const Event* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollSlider : public RectSlider {
    public:

        ScrollSlider(Window* parent, const ButtonColorScheme& colors,
                     const Vector2<int>& slide, const Vector2<int>& pos,
                     const Vector2<size_t>& size);

        ~ScrollSlider() override = default;

    protected:

        bool onMouseMove(const MouseEvent* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollButton : public RectButton {
    protected:

        Mouse::ScrollDelta delta;

    public:

        ScrollButton(Window* parent, Mouse::ScrollDelta delta,
                     const ButtonColorScheme& colors,
                     const Vector2<int>& pos,
                     const Vector2<size_t>& size);

        ~ScrollButton() override = default;

        void setDelta(Mouse::ScrollDelta mouse_delta) {
            delta = mouse_delta;
        }

    protected:

        void reactOnButton(const MouseButtonEvent* event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
