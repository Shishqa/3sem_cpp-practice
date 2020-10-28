/*============================================================================*/
#include "ShishGL/ui/scrollbar/slider.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ScrollbarSlider::ScrollbarSlider(Window *parent, const ButtonColorScheme &colors,
                                 const Vector2<int>& pos,
                                 const Vector2<int>& guide,
                                 const Vector2<size_t>& size)
        : RectFloat(parent, colors, pos, size)
        , guide(guide)
        , curr_ratio(.0) {}

/*----------------------------------------------------------------------------*/

void ScrollbarSlider::onMouseMove(const Event*) {




}

/*============================================================================*/