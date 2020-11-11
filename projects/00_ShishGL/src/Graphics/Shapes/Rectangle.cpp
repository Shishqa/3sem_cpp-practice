/*============================================================================*/
#include "Rectangle.hpp"
#include "CoreApplication.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Rectangle::Rectangle(Object::ID id,
                     const Vector2<double> &size,
                     const Vector2<double> &pos)
        : Shape2D(id, pos)
        , size(size)
        { }

/*----------------------------------------------------------------------------*/

Rectangle::Rectangle(Object::ID id, const Color& color,
                     const Vector2<double>& size,
                     const Vector2<double>& pos)
        : Shape2D(id, color, pos)
        , size(size)
        { }

/*----------------------------------------------------------------------------*/

Vector2<double> Rectangle::getCenter() const {
    return getPos() + 0.5 * size;
}

void Rectangle::setCenter(const Vector2<double>& new_center) {
    setPos(new_center - 0.5 * size);
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Rectangle::getSize() const {
    return size;
}

void Rectangle::setSize(const Vector2<double>& new_size) {
    size = new_size;
}

/*----------------------------------------------------------------------------*/

bool Rectangle::onRender() {
    CoreApplication::System().setColor(color);
    CoreApplication::System().drawRectangle(getPos(), size);
    return true;
}

/*----------------------------------------------------------------------------*/

bool Rectangle::contains(const Vector2<double>& point) const {
    return (getPos().x <= point.x && point.x <= getPos().x + size.x &&
            getPos().y <= point.y && point.y <= getPos().y + size.y);
}

/*----------------------------------------------------------------------------*/

Vector2<double> Rectangle::overallDimension() const {
    return size;
}

/*============================================================================*/
