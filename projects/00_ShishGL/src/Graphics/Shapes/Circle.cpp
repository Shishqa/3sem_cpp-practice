/*============================================================================*/
#include "Circle.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Circle::Circle(Object::ID id, const double &radius,
               const Vector2<double> &pos)
        : Shape2D(id, pos)
        , radius(radius)
        { }

/*----------------------------------------------------------------------------*/

Circle::Circle(Object::ID id, const Color& color,
               const double &radius,
               const Vector2<double> &pos)
        : Shape2D(id, color, pos)
        , radius(radius)
        { }

/*----------------------------------------------------------------------------*/

const double& Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(const double &new_radius) {
    radius = new_radius;
}

/*----------------------------------------------------------------------------*/

Vector2<double> Circle::getCenter() const {
    return (getPos() + Vector2<double>{radius, radius});
}

void Circle::setCenter(const Vector2<double>& new_center) {
    setPos(new_center - Vector2<double>{radius, radius});
}

/*----------------------------------------------------------------------------*/

bool Circle::onRender() {
    RENDERER().setColor(color);
    RENDERER().drawCircle(getPos(), radius);
    return true;
}

/*----------------------------------------------------------------------------*/

bool Circle::contains(const Vector2<double>& point) const {
    return ((point - getCenter()).length() <= radius);
}

/*----------------------------------------------------------------------------*/

Vector2<double> Circle::overallDimension() const {
    return 2.0 * Vector2<double>{radius, radius};
}

/*============================================================================*/
