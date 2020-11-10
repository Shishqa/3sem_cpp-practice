/*============================================================================*/
#ifndef INC_00_SHISHGL_RECTANGLE_HPP
#define INC_00_SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "ShishGL/core/engine/engine.hpp"
#include "ShishGL/Core/Platform/Primitives/Color.hpp"
#include "ShishGL/Core/Platform/Primitives/Vector2.hpp"
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

        void render() override {

            Engine::drawRectangle(getPos(), size);

#ifdef DRAW_GUIDES
            Engine::setColor(RED);
            Engine::drawLine(getRealPos(),
                             getRealPos() + Vector2<int>{static_cast<int>(size.x), 0});
            Engine::drawLine(getRealPos() + Vector2<int>{static_cast<int>(size.x), 0},
                             getRealPos() + Vector2<int>{static_cast<int>(size.x), static_cast<int>(size.y)});
            Engine::drawLine(getRealPos() + Vector2<int>{0, static_cast<int>(size.y)},
                             getRealPos() + Vector2<int>{static_cast<int>(size.x), static_cast<int>(size.y)});
            Engine::drawLine(getRealPos(),
                             getRealPos() + Vector2<int>{0, static_cast<int>(size.y)});

            Engine::setColor(BLUE);
            Engine::drawPoint(getPos());
#endif
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
