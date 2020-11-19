/*============================================================================*/
#ifndef SHISHGL_VIEWPORT_HPP
#define SHISHGL_VIEWPORT_HPP
/*============================================================================*/
#include "Vector2.hpp"
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    struct Viewport {

        Vector2<double> pos;
        Vector2<double> size;
        Vector2<double> display_pos;
        Vector2<double> display_size;

        void recountDisplay();

        void fit_into(const Viewport& other);

        void fit(const Shape2D& shape);

        [[nodiscard]]
        Vector2<double> remap(const Vector2<double> &point) const;
    };

}
/*============================================================================*/
#endif //SHISHGL_VIEWPORT_HPP
/*============================================================================*/
