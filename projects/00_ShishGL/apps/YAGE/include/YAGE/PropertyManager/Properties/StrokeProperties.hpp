/*============================================================================*/
#ifndef SHISHGL_STROKE_PROPERTIES_HPP
#define SHISHGL_STROKE_PROPERTIES_HPP
/*============================================================================*/
#include <cstddef>

#include "Color.hpp"
#include "ColorCollection.hpp"
using namespace ShishGL;
/*============================================================================*/
namespace YAGE {

    class StrokeProperties {
    public:

        /*--------------------------------------------------------------------*/
        static constexpr Color DEFAULT_COLOR = COLOR::GREEN;

        static const Color& activeColor();

        static void setColor(const Color& new_color);
        /*--------------------------------------------------------------------*/

        /*--------------------------------------------------------------------*/
        static constexpr size_t DEFAULT_THICKNESS = 20;

        static const size_t& activeThickness();

        static void setThickness(const size_t& new_thickness);
        /*--------------------------------------------------------------------*/

    private:

        static Color& color();

        static size_t& thickness();

    };

}
/*============================================================================*/
#endif //SHISHGL_STROKE_PROPERTIES_HPP
/*============================================================================*/
