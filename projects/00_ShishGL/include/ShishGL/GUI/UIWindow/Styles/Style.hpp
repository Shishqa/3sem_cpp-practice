/*============================================================================*/
#ifndef SHISHGL_STYLE_HPP
#define SHISHGL_STYLE_HPP
/*============================================================================*/
#include "GUI/UIWindow/Shapes/Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    class Style {
    public:

        Style() = default;

        virtual void apply(Viewport& viewport, const Shape2D& shape) = 0;

        virtual ~Style() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_STYLE_HPP
/*============================================================================*/
