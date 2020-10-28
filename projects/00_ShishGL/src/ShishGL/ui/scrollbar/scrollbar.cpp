/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/ui/scrollbar/scrollbar.hpp"
#include "ShishGL/ui/scrollbar/slider.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(Window* parent, const ScrollbarColorscheme& colors,
                     const Vector2<int>& pos,
                     const Vector2<size_t>& size)
        : RectWindow(parent, colors.bg, pos, size) {

}

/*============================================================================*/
