/*============================================================================*/
#include "ShishGL/widgets/scrollbar/scrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollbarSlider::ScrollbarSlider(Window *parent, const ButtonColorScheme &colors,
                                 const Vector2<int>& slide,
                                 const Vector2<int>& pos,
                                 const Vector2<size_t>& size)
        : RectSlider(parent, colors, slide, pos, size) {}

/*----------------------------------------------------------------------------*/

bool ScrollbarSlider::onMouseMove(const MouseEvent* event) {
    /* todo: send something */
    return RectSlider::onMouseMove(event);
}

/*============================================================================*/