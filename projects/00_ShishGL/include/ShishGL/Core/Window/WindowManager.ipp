/*============================================================================*/
#ifndef SHISHGL_WINDOW_MANAGER_IPP
#define SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename SomeWindow, typename SomeShape, typename... Args>
    SomeWindow* WindowManager::create(Args&&... args) {

        auto* shape = new SomeShape(std::forward<Args>(args)...);
        auto* win = new SomeWindow(shape);

        putRoot(win);

        return win;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/