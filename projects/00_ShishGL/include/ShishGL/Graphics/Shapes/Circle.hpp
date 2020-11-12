/*============================================================================*/
#ifndef SHISHGL_CIRCLE_HPP
#define SHISHGL_CIRCLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    class Circle : public Shape2D {
    public:

        Circle(Object::ID id, const double& radius,
               const Vector2<double>& pos = {0, 0});

        Circle(Object::ID id, const Color& color,
               const double& radius,
               const Vector2<double>& pos = {0, 0});

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        Vector2<double> getCenter() const;

        void setCenter(const Vector2<double>& new_center);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const double& getRadius() const;

        void setRadius(const double& new_radius);

        /*--------------------------------------------------------------------*/

        bool onRender() override;

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        [[nodiscard]]
        Vector2<double> overallDimension() const override;

    protected:

        double radius;

    };

}
/*============================================================================*/
#endif //SHISHGL_CIRCLE_HPP
/*============================================================================*/
