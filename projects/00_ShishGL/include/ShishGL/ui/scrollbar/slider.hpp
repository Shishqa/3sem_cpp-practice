/*============================================================================*/
#ifndef SHISHGL_SCROLLBAR_SLIDER_HPP
#define SHISHGL_SCROLLBAR_SLIDER_HPP
/*============================================================================*/
#include "ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    class ScrollbarSlider : public RectFloat {
    protected:

        Vector2<int> guide;
        double curr_ratio;

    public:

        ScrollbarSlider(Window* parent, const ButtonColorScheme& colors,
                        const Vector2<int>& pos, const Vector2<int>& guide,
                        const Vector2<size_t>& size);

        ~ScrollbarSlider() override = default;

    protected:

        void onMouseMove(const Event* event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLBAR_SLIDER_HPP
/*============================================================================*/
