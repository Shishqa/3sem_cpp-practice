/*============================================================================*/
#ifndef SHISHGL_SLIDABLE_WINDOW_HPP
#define SHISHGL_SLIDABLE_WINDOW_HPP
/*============================================================================*/
#include "DraggableWindow.hpp"
#include "Segment2.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    class SlidableWindow : public DraggableWindow<Shape> {
    public:

        template <typename... Args>
        SlidableWindow(Object::ID id, Object::ID parent,
                       const Segment2<double>& slide,
                       Args&&... args);

        ~SlidableWindow() override = default;

    protected:

        bool onMouseMove(MouseEvent& event) override;

    private:

        Segment2<double> slide_seg;

    };

}
/*============================================================================*/
#include "../../../../src/GUI/Interactables/SlidableWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_SLIDABLE_WINDOW_HPP
/*============================================================================*/
