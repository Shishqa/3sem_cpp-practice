/*============================================================================*/
#include "ShishGL/window/rect_window.hpp"
#include "ShishGL/core/core_application.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

RectWindow::RectWindow(Window *parent, const Vector2<int> &pos,
                       const Vector2<size_t> &size,
                       const Color& color)
    : Window(parent, pos)
    , size(size)
    , color(color) {}

/*----------------------------------------------------------------------------*/

void RectWindow::onRender() {
    Engine::setColor(color);
    Engine::drawRectangle(abs_pos, size);
}

/*----------------------------------------------------------------------------*/

bool RectWindow::contains(const Vector2<int>& point) {
    return (abs_pos.x <= point.x && point.x <= abs_pos.x + static_cast<int>(size.x) &&
            abs_pos.y <= point.y && point.y <= abs_pos.y + static_cast<int>(size.y));
}

/*----------------------------------------------------------------------------*/



/*============================================================================*/

