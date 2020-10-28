/*============================================================================*/
#include "ShishGL/ui/scrollbar/slider.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollbarSlider::ScrollbarSlider(Window *parent, const ButtonColorScheme &colors,
                                 const Vector2<int>& slide,
                                 const Vector2<int>& pos,
                                 const Vector2<size_t>& size)
        : RectSlider(parent, colors, slide, pos, size) {}

/*----------------------------------------------------------------------------*/

void ScrollbarSlider::onMouseMove(const Event* event) {
    /* todo: send something */
    RectSlider::onMouseMove(event);
}

/*============================================================================*/