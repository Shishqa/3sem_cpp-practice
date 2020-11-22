/*============================================================================*/
#include "RectangleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void RectangleShape::draw(const Viewport& viewport) const {
    RENDERER().drawRectangle(viewport.pos, viewport.size);
}

/*----------------------------------------------------------------------------*/

bool RectangleShape::contains(const Viewport &viewport,
                              const Vector2<double> &point) const {
    return (viewport.pos.x <= point.x && point.x <= viewport.pos.x + viewport.size.x &&
            viewport.pos.y <= point.y && point.y <= viewport.pos.y + viewport.size.y);
}

/*============================================================================*/
