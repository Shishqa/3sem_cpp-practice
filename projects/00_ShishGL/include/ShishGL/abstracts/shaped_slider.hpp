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
        ShapedSlider(Object::ID id, Object::ID parent, const ButtonColorScheme& colors,
                     const Vector2<double>& guide,
                     Args&&... args)
            : ShapedFloat<SomeShape>(id, parent, colors, std::forward<Args>(args)...)
            , guide(guide)
            , guide_pos({}) {
            guide_pos = ShapedFloat<SomeShape>::getAbsPos();
        }

        ~ShapedSlider() override = default;

        [[nodiscard]]
        const Vector2<double>& getGuide() const { return guide; }

        /*--------------------------------------------------------------------*/

        void slide(double delta_in_pixels) override {
            advance(delta_in_pixels * !guide);
        }

        /*--------------------------------------------------------------------*/

    protected:

        Vector2<double> advance(const Vector2<double>& delta) {

            Vector2<double> delta_projected = delta | guide;
            auto curr_pos = ShapedFloat<SomeShape>::getAbsPos();

            Vector2<double> dest = curr_pos + delta_projected;

            Vector2<double> max_pos = guide_pos + guide;
            if (((dest - guide_pos) ^ guide) <= 0) {
                dest = guide_pos;
            } else if (((dest - max_pos) ^ guide) >= 0) {
                dest = max_pos;
            }

            ShapedFloat<SomeShape>::move_to(dest);

            return dest - curr_pos;
        }

        /*--------------------------------------------------------------------*/

        bool onMouseMove(const MouseEvent* event) override {

            if (!ShapedButton<SomeShape>::is_pressed) {
                return false;
            }

            auto drag_delta = event->where() - ShapedFloat<SomeShape>::where_dragged;

            ShapedFloat<SomeShape>::where_dragged += advance(drag_delta);

            return true;
        }
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_SLIDER_HPP
/*============================================================================*/
