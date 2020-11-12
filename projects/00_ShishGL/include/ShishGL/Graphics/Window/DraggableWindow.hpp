/*============================================================================*/
#ifndef SHISHGL_DRAGGABLE_WINDOW_HPP
#define SHISHGL_DRAGGABLE_WINDOW_HPP
/*============================================================================*/
#include "Vector2.hpp"
#include "HoldableWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    class DraggableWindow : public HoldableWindow<Shape> {
    public:

        template <typename... Args>
        DraggableWindow(Object::ID id, Object::ID parent, Args&&... args);

        ~DraggableWindow() override = default;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseMove(MouseEvent& event) override;

        [[nodiscard]]
        const Vector2<double>& dragPoint() const;

    private:

        Vector2<double> drag_point;

    };

}
/*============================================================================*/
#include "DraggableWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_DRAGGABLE_WINDOW_HPP
/*============================================================================*/
