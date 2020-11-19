/*============================================================================*/
#include "RectangleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

RectangleShape::RectangleShape(const Vector2<double> &size,
                               const Vector2<double> &pos)
        : Shape2D(pos)
        , size(size)
        { }

/*----------------------------------------------------------------------------*/

Vector2<double> RectangleShape::getCenter() const {
    return getPos() + 0.5 * size;
}

void RectangleShape::setCenter(const Vector2<double>& new_center) {
    setPos(new_center - 0.5 * size);
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& RectangleShape::getSize() const {
    return size;
}

void RectangleShape::setSize(const Vector2<double>& new_size) {
    size = new_size;
}

/*----------------------------------------------------------------------------*/

void RectangleShape::draw() {
    RENDERER().drawRectangle(getPos(), size);
}

/*----------------------------------------------------------------------------*/

bool RectangleShape::contains(const Vector2<double>& point) const {
    return (getPos().x <= point.x && point.x <= getPos().x + size.x &&
            getPos().y <= point.y && point.y <= getPos().y + size.y);
}

/*----------------------------------------------------------------------------*/

Vector2<double> RectangleShape::overallDimension() const {
    return size;
}

/*============================================================================*/
