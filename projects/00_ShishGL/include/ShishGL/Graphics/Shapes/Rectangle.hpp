/*============================================================================*/
#ifndef SHISHGL_RECTANGLE_HPP
#define SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
#include "CoreApplication.hpp"
/*============================================================================*/
namespace ShishGL {

    class Rectangle : public Shape2D {
    public:

        Rectangle(Object::ID id, const Vector2<double>& size,
                  const Vector2<double>& pos = {0, 0});

        Rectangle(Object::ID id, const Color& color,
                  const Vector2<double>& size,
                  const Vector2<double>& pos = {0, 0});

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        Vector2<double> getCenter() const;

        void setCenter(const Vector2<double>& new_center);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getSize() const;

        void setSize(const Vector2<double>& new_size);

        /*--------------------------------------------------------------------*/

        bool onRender() override;

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        [[nodiscard]]
        Vector2<double> overallDimension() const override;

    protected:

        Vector2<double> size;

    };

}
/*============================================================================*/
#endif //SHISHGL_RECTANGLE_HPP
/*============================================================================*/
