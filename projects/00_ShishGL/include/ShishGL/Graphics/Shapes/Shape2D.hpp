/*============================================================================*/
#ifndef SHISHGL_SHAPE_2D_HPP
#define SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
#include "../../Core/GraphicObject.hpp"
#include "Vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D : public GraphicObject {
    public:

        explicit Shape2D(Object::ID id, const Vector2<double>& pos);

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        ~Shape2D() override = default;

    protected:

        Vector2<double> s_pos;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
