/*============================================================================*/
#ifndef INC_00_SHISHGL_SHAPE2D_HPP
#define INC_00_SHISHGL_SHAPE2D_HPP
/*============================================================================*/
#include "ShishGL/core/geometry/vector2.hpp"
#include "ShishGL/core/object/renderable_object.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D : public RenderableObject {
    protected:

        Vector2<double> abs_pos;

    public:

        explicit Shape2D(const Vector2<double>& abs_pos)
            : abs_pos(abs_pos) {}

        virtual ~Shape2D() = default;

        [[nodiscard]]
        const Vector2<double>& getPos() const {
            return abs_pos;
        }

        void translate(const Vector2<double>& delta) {
            abs_pos += delta;
        }

        void move_to(const Vector2<double>& pos) {
            abs_pos = pos;
        }

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const = 0;

        virtual void draw() = 0;

    };

}
/*============================================================================*/
#endif //INC_00_SHISHGL_SHAPE2D_HPP
/*============================================================================*/
