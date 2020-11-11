/*============================================================================*/
#ifndef SHISHGL_RECTANGLE_HPP
#define SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    class Rectangle : public GraphicObject {
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

        void render() override {

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
#endif //SHISHGL_RECTANGLE_HPP
/*============================================================================*/
