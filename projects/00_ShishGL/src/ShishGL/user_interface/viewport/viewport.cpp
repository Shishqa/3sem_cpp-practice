/*============================================================================*/
#include "ShishGL/color/color_collection.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/user_interface/viewport/viewport.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Viewport::Viewport(Window *parent, const Vector2<int> &pos,
                   const Vector2<size_t> &size)
    : RectWindow(parent, WHITE, pos, size) {

    attach<Scrollbar>(
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<int>{static_cast<int>(size.x - SCROLLBAR_WIDTH), 0},
            Vector2<size_t>{SCROLLBAR_WIDTH, size.y - SCROLLBAR_WIDTH}
            );

}

/*----------------------------------------------------------------------------*/

void Viewport::onRender() {

    RectWindow::onRender();

}

/*============================================================================*/

