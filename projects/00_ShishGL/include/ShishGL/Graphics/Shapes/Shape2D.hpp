/*============================================================================*/
#ifndef SHISHGL_SHAPE_2D_HPP
#define SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
#include "Renderable.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
/*============================================================================*/
namespace ShishGL {

    class Shape2D : public Renderable {
    public:

        explicit Shape2D(Object::ID id, const Vector2<double>& pos = {0, 0});

        explicit Shape2D(Object::ID id, const Color& color,
                         const Vector2<double>& pos = {0, 0});

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        void setPos(const Vector2<double>& pos);

        void translate(const Vector2<double>& delta);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Color& getColor() const;

        void setColor(const Color& new_color);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const = 0;

        [[nodiscard]]
        virtual Vector2<double> overallDimension() const = 0;

        ~Shape2D() override = default;

    protected:

        Vector2<double> s_pos;
        Color color;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPE_2D_HPP
/*============================================================================*/
