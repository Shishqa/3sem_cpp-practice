/*============================================================================*/
#include "StrokeProperties.hpp"
#include "ColorCollection.hpp"
/*============================================================================*/
using namespace YAGE;
/*============================================================================*/

Color& StrokeProperties::color() {
    static Color COLOR = DEFAULT_COLOR;
    return COLOR;
}

const Color& StrokeProperties::activeColor() {
    return color();
}

void StrokeProperties::setColor(const Color& new_color) {
    color() = new_color;
}

/*============================================================================*/

size_t& StrokeProperties::thickness() {
    static size_t THICKNESS = DEFAULT_THICKNESS;
    return THICKNESS;
}

const size_t& StrokeProperties::activeThickness() {
    return thickness();
}

void StrokeProperties::setThickness(const size_t& new_thickness) {
    thickness() = new_thickness;
}

/*============================================================================*/
