/*============================================================================*/
#ifndef SHISHGL_SHAPED_SLIDER_HPP
#define SHISHGL_SHAPED_SLIDER_HPP
/*============================================================================*/
#include "shaped_float.hpp"
#include "ShishGL/ables/scrollable.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedSlider : public ShapedFloat<SomeShape>, public Slidable {
    protected:

        Vector2<double> guide;
        Vector2<double> guide_pos;

    public:

        template <typename... Args>
        ShapedSlider(Window* parent, const ButtonColorScheme& colors,
                     const Vector2<int>& guide,
                     Args&&... args)
            : ShapedFloat<SomeShape>(parent, colors, std::forward<Args>(args)...)
            , guide(static_cast<Vector2<double>>(guide))
            , guide_pos({}) {

            guide_pos = static_cast<Vector2<double>>(ShapedFloat<SomeShape>::getAbsPos());
        }

        ~ShapedSlider() override = default;

        /*--------------------------------------------------------------------*/

        void slide(int delta) override {
            advance(static_cast<double>(delta) * !guide);
        }

        /*--------------------------------------------------------------------*/

    protected:

        Vector2<double> advance(const Vector2<double>& delta) {

            auto curr_pos = static_cast<Vector2<double>>(ShapedFloat<SomeShape>::getAbsPos());
            Vector2<double> proj_delta = delta | guide;
            Vector2<double> dest = curr_pos + proj_delta;
            Vector2<double> max_pos = guide_pos + guide;

            if (((dest - guide_pos) ^ guide) <= 0) {
                dest = guide_pos;
            } else if (((dest - max_pos) ^ guide) >= 0) {
                dest = max_pos;
            }

            ShapedFloat<SomeShape>::move_to(static_cast<Vector2<int>>(dest));

            return dest - curr_pos;
        }

        /*--------------------------------------------------------------------*/

        bool onMouseMove(const MouseEvent* event) override {

            if (!ShapedButton<SomeShape>::is_pressed) {
                return false;
            }

            auto drag_delta = static_cast<Vector2<double>>(
                    event->where() -
                    ShapedFloat<SomeShape>::where_dragged
            );

            ShapedFloat<SomeShape>::where_dragged +=
                    static_cast<Vector2<int>>(advance(drag_delta));

            return true;
        }
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_SLIDER_HPP
/*============================================================================*/
