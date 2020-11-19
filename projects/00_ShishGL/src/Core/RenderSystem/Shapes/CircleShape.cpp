/*============================================================================*/
#include "CircleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

CircleShape::CircleShape(const double &radius,
                         const Vector2<double> &pos)
        : Shape2D(pos)
        , radius(radius)
        { }

/*----------------------------------------------------------------------------*/

const double& CircleShape::getRadius() const {
    return radius;
}

void CircleShape::setRadius(const double &new_radius) {
    radius = new_radius;
}

/*----------------------------------------------------------------------------*/

Vector2<double> CircleShape::getCenter() const {
    return (getPos() + Vector2<double>{radius, radius});
}

void CircleShape::setCenter(const Vector2<double>& new_center) {
    setPos(new_center - Vector2<double>{radius, radius});
}

/*----------------------------------------------------------------------------*/

void CircleShape::draw() {
    RENDERER().drawCircle(getPos(), radius);
}

/*----------------------------------------------------------------------------*/

bool CircleShape::contains(const Vector2<double>& point) const {
    return ((point - getCenter()).length() <= radius);
}

/*----------------------------------------------------------------------------*/

Vector2<double> CircleShape::overallDimension() const {
    return 2.0 * Vector2<double>{radius, radius};
}

/*============================================================================*/
