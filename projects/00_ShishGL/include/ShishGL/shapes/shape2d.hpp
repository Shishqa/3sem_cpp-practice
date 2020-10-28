/*============================================================================*/
#ifndef INC_00_SHISHGL_SHAPE2D_HPP
#define INC_00_SHISHGL_SHAPE2D_HPP
/*============================================================================*/
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D {
    protected:

        Vector2<int> abs_pos;

    public:

        explicit Shape2D(const Vector2<int>& abs_pos)
            : abs_pos(abs_pos) {}

        [[nodiscard]]
        const Vector2<int>& getPos() const {
            return abs_pos;
        }

        void translate(const Vector2<int>& delta) {
            abs_pos += delta;
        }

        void move_to(const Vector2<int>& pos) {
            abs_pos = pos;
        }

        virtual bool contains(const Vector2<int>& point) = 0;

        virtual void render() = 0;

    };

}
/*============================================================================*/
#endif //INC_00_SHISHGL_SHAPE2D_HPP
/*============================================================================*/
