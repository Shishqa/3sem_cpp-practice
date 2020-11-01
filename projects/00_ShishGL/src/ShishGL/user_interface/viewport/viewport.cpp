/*============================================================================*/
#include "ShishGL/color/color_collection.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/user_interface/viewport/viewport.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Viewport::Viewport(Window *parent, const Vector2<double>& size,
                   const Vector2<double>& pos)
    : RectWindow(parent, WHITE, size, pos) {

    attach<Scrollbar>(
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<double>{SCROLLBAR_WIDTH, size.y - SCROLLBAR_WIDTH},
            Vector2<double>{size.x - SCROLLBAR_WIDTH, 0}
    );

}

/*----------------------------------------------------------------------------*/

void Viewport::onRender() {

    RectWindow::onRender();

}

/*============================================================================*/

