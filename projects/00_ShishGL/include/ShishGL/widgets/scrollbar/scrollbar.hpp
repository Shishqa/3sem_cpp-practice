/*============================================================================*/
#ifndef SHISHGL_SCROLLBAR_HPP
#define SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
#include "ShishGL/abstracts/scrollable.hpp"
#include "ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    /*========================================================================*/
    struct ScrollbarColorscheme {
        Color bg;
        ButtonColorScheme slider;
        ButtonColorScheme arrow;
    };
    /*------------------------------------------------------------------------*/
    static constexpr ScrollbarColorscheme DEFAULT_SCROLLBAR_COLORS = {
            DARK_SLATE_GREY,
            {PAPAYA_WHIP, WHITE_SMOKE, WHITE},
            {DARK_SEA_GREEN, WHITE_SMOKE, WHITE}
    };
    /*========================================================================*/

    class ScrollbarSlider;

    class ScrollbarButton;

    /*------------------------------------------------------------------------*/

    class Scrollbar : public RectWindow {
    protected:

        Scrollable* scrollable;
        ScrollbarSlider* slider;

    public:

        Scrollbar(Window* parent, Scrollable* scrollable,
                  const ScrollbarColorscheme& colors,
                  const Vector2<int>& pos,
                  const Vector2<size_t>& size);

        ~Scrollbar() override = default;

    protected:

        bool filterEvent(const Event* event) override;

        bool onMouseScroll(const MouseScrollEvent* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollbarSlider : public RectSlider {
    public:

        ScrollbarSlider(Window* parent, const ButtonColorScheme& colors,
                        const Vector2<int>& slide, const Vector2<int>& pos,
                        const Vector2<size_t>& size);

        ~ScrollbarSlider() override = default;

    protected:

        bool onMouseMove(const MouseEvent* event) override;

    };

    /*------------------------------------------------------------------------*/

    class ScrollButton : public RectButton {
    public:

        ScrollUpButton(Window* parent, const ButtonColorScheme& colors,
                       const Vector2<int>& pos,
                       const Vector2<size_t>& size);

        ~ScrollUpButton() override = default;

    protected:

        void reactOnButton(const MouseButtonEvent*) override {}

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
