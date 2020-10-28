/*============================================================================*/
#ifndef INC_00_SHISHGL_RECTANGLE_HPP
#define INC_00_SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "ShishGL/core/engine.hpp"
#include "ShishGL/utility/color.hpp"
#include "ShishGL/geometry/vector2.hpp"
#include "shape2d.hpp"
/*============================================================================*/
namespace ShishGL {

    class Rectangle : public Shape2D {
    protected:

        Vector2<size_t> size;

    public:

        Rectangle(const Vector2<int>& pos,
                  const Vector2<size_t>& size)
            : Shape2D(pos)
            , size(size) {}

        void render() override {
            Engine::drawRectangle(abs_pos, size);
        }

        bool contains(const Vector2<int>& point) override {
            return (abs_pos.x <= point.x && point.x <= abs_pos.x + static_cast<int>(size.x) &&
                    abs_pos.y <= point.y && point.y <= abs_pos.y + static_cast<int>(size.y));
        }

    };

}
/*============================================================================*/
#endif //INC_00_SHISHGL_RECTANGLE_HPP
/*============================================================================*/
