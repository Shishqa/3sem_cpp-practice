/*============================================================================*/
#ifndef SHISHGL_DRAGGABLE_WINDOW_IPP
#define SHISHGL_DRAGGABLE_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    template <typename... Args>
    DraggableWindow<Shape>::DraggableWindow(Object::ID id, Object::ID parent,
                                            Args&&... args)
        : HoldableWindow<Shape>(id, parent, std::forward<Args>(args)...)
        , drag_point({0, 0})
        { }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool DraggableWindow<Shape>::onMouseButton(MouseButtonEvent& event) {

        HoldableWindow<Shape>::onMouseButton(event);

        if (Mouse::DOWN == event.state() &&
            1 == HoldableWindow<Shape>::numHolded()) {
            drag_point = event.where();
        }

        return true;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool DraggableWindow<Shape>::onMouseMove(MouseEvent& event) {

        HoldableWindow<Shape>::onMouseMove(event);

        if (HoldableWindow<Shape>::isHolded()) {
            Window<Shape>::getShape().translate(event.where() - drag_point);
            drag_point = event.where();
        }

        return true;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    const Vector2<double>& DraggableWindow<Shape>::dragPoint() const {
        return drag_point;
    }

}
/*============================================================================*/
#endif //SHISHGL_DRAGGABLE_WINDOW_IPP
/*============================================================================*/
