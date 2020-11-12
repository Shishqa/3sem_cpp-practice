/*============================================================================*/
#ifndef SHISHGL_CLICKABLE_WINDOW_IPP
#define SHISHGL_CLICKABLE_WINDOW_IPP
/*============================================================================*/
#include "MouseEvent.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    template <typename... Args>
    ClickableWindow<Shape>::ClickableWindow(Object::ID id, Object::ID parent,
                                            Args&&... args)
        : Window<Shape>(id, parent, std::forward<Args>(args)...)
        { }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool ClickableWindow<Shape>::filterEvent(const Event& event) const try {

        auto mouse_button = dynamic_cast<const MouseButtonEvent&>(event);

        if (mouse_button.state() != Mouse::DOWN) {
            return true;
        }

        if (!Window<Shape>::getShape().contains(mouse_button.where())) {
            return false;
        }
        return true;

    } catch (...) {

        return true;

    }

}
/*============================================================================*/
#endif //SHISHGL_CLICKABLE_WINDOW_IPP
/*============================================================================*/
