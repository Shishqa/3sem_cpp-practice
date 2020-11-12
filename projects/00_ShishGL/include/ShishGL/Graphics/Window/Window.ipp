/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    template <typename... Args>
    Window<Shape>::Window(Object::ID id, Object::ID parent, Args&&... args)
            : SystemObject(id)
            , is_active(false)
            , parent(parent) {
        shape = CREATE<ShapeHelper<Shape, Shape>>(std::forward<Args>(args)...);
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    template <typename SomeWindow, typename... Args>
    Object::ID Window<Shape>::attach(Args&&... args) {

        Object::ID subwindow =
                CREATE<WindowHelper<SomeWindow, SomeWindow>>(std::forward<Args>(args)...);

        subwindows.insert(subwindow);

        return subwindow;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    Window<Shape>::~Window() {
        for (auto& subwindow : subwindows) {
            REMOVE(subwindow);
        }
        REMOVE(shape);
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool Window<Shape>::detach(Object::ID subwindow) {
        bool status = subwindows.erase(subwindow);
        if (status) {
            REMOVE(subwindow);
        }
        return status;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool Window<Shape>::onMouseEntered(MouseEvent&) { return false; }

    template <typename Shape>
    bool Window<Shape>::onMouseLeft(MouseEvent &) { return false; }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool Window<Shape>::onMouseMove(MouseEvent& event) {

        bool is_event_inside = getShape().contains(event.where());

        if (is_active && !is_event_inside) {

            is_active = false;
            return onMouseLeft(event);

        } else if (!is_active && is_event_inside) {

            is_active = true;
            return onMouseEntered(event);
        }

        return SystemObject::onMouseMove(event);
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    Shape& Window<Shape>::getShape() const {
        return GET<Shape>(shape);
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
