/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape, typename... Args>
    void Window::applyShape(Args&&... args) {
        applyShape(new SomeShape(std::forward<Args>(args)...));
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeMouseEvent>
    bool Window::resendMouse(SomeMouseEvent& event) {

        Vector2<double> where = event.where();
        event.setWhere(viewport.remap(where));

        bool status = EventSystem::sendEvent(this, event);

        event.setWhere(where);

        return status;
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeStyle, typename... Args>
    void Window::applyStyle(Args&&... args) {
        auto style = new SomeStyle(std::forward<Args>(args)...);
        styles.push_back(style);
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
