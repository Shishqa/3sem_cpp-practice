/*============================================================================*/
#ifndef SHISHGL_HOLDABLE_WINDOW_IPP
#define SHISHGL_HOLDABLE_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    template <typename... Args>
    HoldableWindow<Shape>::HoldableWindow(Object::ID id, Object::ID parent,
                                          Args&&... args)
        : ClickableWindow<Shape>(id, parent, std::forward<Args>(args)...)
        , n_holded(0)
        { }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool HoldableWindow<Shape>::onMouseButton(MouseButtonEvent& event) {

        if (Mouse::DOWN == event.state()) {
            ++n_holded;
        } else {
            n_holded = (n_holded ? n_holded - 1 : 0);
        }

        return true;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    uint8_t HoldableWindow<Shape>::numHolded() const {
        return n_holded;
    }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool HoldableWindow<Shape>::isHolded() const {
        return (n_holded > 0);
    }

}
/*============================================================================*/
#endif //SHISHGL_HOLDABLE_WINDOW_IPP
/*============================================================================*/