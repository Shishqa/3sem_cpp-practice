/*============================================================================*/
#ifndef SHISHGL_SHAPE_2D_HPP
#define SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
#include "Viewport.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D {
    public:

        [[nodiscard]]
        virtual bool contains(const Viewport& viewport,
                              const Vector2<double>& point) const = 0;

        virtual void draw(const Viewport& viewport) const = 0;

        virtual ~Shape2D() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
