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

        Vector2<int> where_dragged = {};
        bool is_dragged;

    public:

        template <typename... Args>
        explicit ShapedFloat(Window* parent, const ButtonColorScheme& colors,
                             Args&&... args)
                : ShapedButton<SomeShape>(parent, colors,
                                          std::forward<Args>(args)...)
                , is_dragged(false) {}

    protected:

        void reactOnClick(const Event* event) override {
            is_dragged = true;
            where_dragged = event->mouse.where;
        }

        void reactOnRelease(const Event*) override {
            is_dragged = false;
        }

        void onMouseMove(const Event* event) override {
            if (is_dragged) {
                ShapedWindow<SomeShape>::translate(event->mouse_cursor.where - where_dragged);
                where_dragged = event->mouse_cursor.where;
            }
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_FLOAT_HPP
/*============================================================================*/
