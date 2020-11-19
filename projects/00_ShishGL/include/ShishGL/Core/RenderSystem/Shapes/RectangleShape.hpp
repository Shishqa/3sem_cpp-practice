/*============================================================================*/
#ifndef SHISHGL_RECTANGLE_HPP
#define SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    class RectangleShape : public Shape2D {
    public:

        explicit RectangleShape(const Vector2<double>& size,
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

        void draw() override;

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
