/*============================================================================*/
#ifndef SHISHGL_SHAPED_SLIDER_HPP
#define SHISHGL_SHAPED_SLIDER_HPP
/*============================================================================*/
#include "shaped_float.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedSlider : public ShapedFloat<SomeShape> {
    protected:

        Vector2<double> slide;
        Vector2<double> slide_pos;

    public:

        template <typename... Args>
        ShapedSlider(Window* parent, const ButtonColorScheme& colors,
                     const Vector2<int>& slide_vec,
                     Args&&... args)
            : ShapedFloat<SomeShape>(parent, colors, std::forward<Args>(args)...)
            , slide(static_cast<Vector2<double>>(slide_vec))
            , slide_pos({}) {

            slide_pos = static_cast<Vector2<double>>(ShapedFloat<SomeShape>::getAbsPos());
        }

        ~ShapedSlider() override = default;

        void advance(double ratio) {
            Vector2<double> delta = static_cast<double>(ratio) * slide;
            advance(delta);
        }

    protected:

        Vector2<double> advance(const Vector2<double>& delta) {

            auto curr_pos = static_cast<Vector2<double>>(ShapedFloat<SomeShape>::getAbsPos());
            Vector2<double> proj_delta = delta | slide;
            Vector2<double> dest = curr_pos + proj_delta;
            Vector2<double> max_pos = slide_pos + slide;

            if (((dest - slide_pos) ^ slide) <= 0) {
                dest = slide_pos;
            } else if (((dest - max_pos) ^ slide) >= 0) {
                dest = max_pos;
            }

            ShapedFloat<SomeShape>::move_to(static_cast<Vector2<int>>(dest));

            return dest - curr_pos;
        }

        void onMouseMove(const Event* event) override {

            if (!ShapedFloat<SomeShape>::is_dragged) {
                return;
            }

            auto drag_delta = static_cast<Vector2<double>>(
                    event->mouse_cursor.where -
                    ShapedFloat<SomeShape>::where_dragged
            );

            ShapedFloat<SomeShape>::where_dragged +=
                    static_cast<Vector2<int>>(advance(drag_delta));

        }
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_SLIDER_HPP
/*============================================================================*/
