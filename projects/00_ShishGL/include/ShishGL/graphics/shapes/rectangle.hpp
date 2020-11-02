/*============================================================================*/
#ifndef INC_00_SHISHGL_RECTANGLE_HPP
#define INC_00_SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "ShishGL/core/engine/engine.hpp"
#include "ShishGL/core/color.hpp"
#include "ShishGL/core/geometry/vector2.hpp"
#include "shape2d.hpp"
/*============================================================================*/
namespace ShishGL {

    class Rectangle : public Shape2D {
    protected:

        Vector2<double> size;

    public:

        explicit Rectangle(const Vector2<double>& size,
                           const Vector2<double>& pos = {0, 0})
            : Shape2D(pos)
            , size(size) {}

        /*--------------------------------------------------------------------*/

        void setCenter(const Vector2<double>& new_center) {
            move_to(new_center - 0.5 * size);
        }

        [[nodiscard]]
        inline Vector2<double> getCenter() const {
            return getPos() + 0.5 * size;
        };

        /*--------------------------------------------------------------------*/

        void draw() override {
            Engine::drawRectangle(getPos(), size);
        }

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override {
            return (getPos().x <= point.x && point.x <= getPos().x + size.x &&
                    getPos().y <= point.y && point.y <= getPos().y + size.y);
        }

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getSize() const { return size; }

    };

}
/*============================================================================*/
#endif //INC_00_SHISHGL_RECTANGLE_HPP
/*============================================================================*/
