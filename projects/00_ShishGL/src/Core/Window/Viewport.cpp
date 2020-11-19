/*============================================================================*/
#include "Viewport.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void Viewport::recountDisplay() {

    display_size = Vector2<double>{
            size.x / RENDERER().getDisplaySize().x,
            size.y / RENDERER().getDisplaySize().y
    };

    display_pos = Vector2<double>{
            pos.x / RENDERER().getDisplaySize().x,
            pos.y / RENDERER().getDisplaySize().y
    };
}

/*----------------------------------------------------------------------------*/

void Viewport::fit(const Shape2D& shape) {
    pos = shape.getPos();
    size = shape.overallDimension();
}

/*----------------------------------------------------------------------------*/

void Viewport::fit_into(const Viewport& other) {

    size.x = std::min(size.x, other.pos.x + other.size.x - pos.x);
    size.y = std::min(size.y, other.pos.y + other.size.y - pos.y);

    if (pos.x < other.pos.x) {
        size.x -= other.pos.x - pos.x;
        pos.x = other.pos.x;
    }

    if (pos.y < other.pos.y) {
        size.y -= other.pos.y - pos.y;
        pos.y = other.pos.y;
    }

    recountDisplay();
}

/*----------------------------------------------------------------------------*/

Vector2<double> Viewport::remap(const Vector2<double> &point) const {
    return point - pos;
}

/*============================================================================*/