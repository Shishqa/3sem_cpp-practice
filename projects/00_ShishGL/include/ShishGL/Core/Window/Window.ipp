/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
#include "__WindowManager.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeWindow, typename SomeShape, typename... Args>
    Object::ID Window::attach(Args&&... args) {
        return WindowManager::create<SomeWindow, SomeShape>(id(), std::forward<Args>(args)...);
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeWindow, typename SomeShape, typename... Args>
    Object::ID Window::attachSubscribe(Args&&... args) {

        Object::ID child =
                WindowManager::create<SomeWindow, SomeShape>(id(), std::forward<Args>(args)...);

        SubscriptionManager::subscribe(this, &GET<Window>(child));

        return child;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
