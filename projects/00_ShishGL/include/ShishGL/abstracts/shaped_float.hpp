/*============================================================================*/
#ifndef SHISHGL_SHAPED_FLOAT_HPP
#define SHISHGL_SHAPED_FLOAT_HPP
/*============================================================================*/
#include "shaped_button.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedFloat : public ShapedButton<SomeShape> {
    protected:

        Vector2<double> where_dragged = {};

    public:

        template <typename... Args>
        explicit ShapedFloat(Window* parent, const ButtonColorScheme& colors,
                             Args&&... args)
                : ShapedButton<SomeShape>(parent, colors,
                                          std::forward<Args>(args)...) {}

        ~ShapedFloat() override = default;

    protected:

        void reactOnButton(const MouseButtonEvent* event) override {
            if (event->state() == Mouse::DOWN) {
                where_dragged = event->where();
            }
        }

        bool onMouseMove(const MouseEvent* event) override {
            if (ShapedButton<SomeShape>::is_pressed) {
                ShapedWindow<SomeShape>::translate(event->where() - where_dragged);
                where_dragged = event->where();
            }
            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_FLOAT_HPP
/*============================================================================*/
