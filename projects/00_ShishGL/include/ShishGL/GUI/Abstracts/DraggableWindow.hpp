/*============================================================================*/
#ifndef SHISHGL_DRAGGABLE_WINDOW_HPP
#define SHISHGL_DRAGGABLE_WINDOW_HPP
/*============================================================================*/
#include "Vector2.hpp"
#include "HoldableWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    class DraggableWindow : public HoldableWindow {
    public:

        explicit DraggableWindow(Shape2D* shape);

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
#endif //SHISHGL_DRAGGABLE_WINDOW_HPP
/*============================================================================*/
