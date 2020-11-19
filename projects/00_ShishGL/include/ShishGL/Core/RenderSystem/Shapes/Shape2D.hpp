/*============================================================================*/
#ifndef SHISHGL_SHAPE_2D_HPP
#define SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
#include "Vector2.hpp"
#include "Color.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D {
    public:

        explicit Shape2D(const Vector2<double>& pos = {0, 0});

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        void setPos(const Vector2<double>& pos);

        void translate(const Vector2<double>& delta);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const = 0;

        [[nodiscard]]
        virtual Vector2<double> overallDimension() const = 0;

        /*--------------------------------------------------------------------*/

        virtual void draw() = 0;

        virtual ~Shape2D() = default;

    protected:

        Vector2<double> s_pos;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
