/*============================================================================*/
#ifndef SHISHGL_SCROLLBAR_HPP
#define SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
#include "ShishGL/window.hpp"
#include "slider.hpp"
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

    class Scrollbar : public RectWindow {
    protected:

        static constexpr int SCROLL_EVENT = 101;

        ScrollbarSlider* slider;

    public:

        Scrollbar(Window* parent, const ScrollbarColorscheme& colors,
                  const Vector2<int>& pos,
                  const Vector2<size_t>& size);

        ~Scrollbar() override = default;

    protected:

        void onMouseScroll(const Event* event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_HPP
/*============================================================================*/
