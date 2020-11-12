/*============================================================================*/
#include "Shape2D.hpp"
#include "../../../include/ShishGL/Graphics/ColorCollection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Shape2D::Shape2D(Object::ID id, const Vector2<double> &pos)
    : GraphicObject(id)
    , s_pos(pos)
    , color(BLACK)
    { }

/*----------------------------------------------------------------------------*/

Shape2D::Shape2D(Object::ID id, const Color& color,
                 const Vector2<double>& pos)
    : GraphicObject(id)
    , s_pos(pos)
    , color(color)
    { }

/*----------------------------------------------------------------------------*/

const Vector2<double>& Shape2D::getPos() const {
    return s_pos;
}

/*----------------------------------------------------------------------------*/

void Shape2D::setPos(const Vector2<double>& pos) {
    s_pos = pos;
}

/*----------------------------------------------------------------------------*/

void Shape2D::translate(const Vector2<double>& delta) {
    s_pos += delta;
}

/*----------------------------------------------------------------------------*/

const Color& Shape2D::getColor() const {
    return color;
}

/*----------------------------------------------------------------------------*/

void Shape2D::setColor(const Color& new_color) {
    color = new_color;
}

/*============================================================================*/
