/*============================================================================*/
#ifndef SHISHGL_WINDOW_MANAGER_IPP
#define SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename SomeWindow, typename SomeShape, typename... Args>
    Object::ID WindowManager::create(Args&&... args) {

        Object::ID shape = CREATE<SomeShape>(std::forward<Args>(args)...);

        Object::ID win = CREATE<SomeWindow>(shape);
        GET<Window>(win).initLayout();

        return win;
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeWindow, typename SomeShape, typename... Args>
    Object::ID WindowManager::create(Object::ID parent, Args&&... args) {

        Object::ID shape = CREATE<SomeShape>(std::forward<Args>(args)...);

        Object::ID win = CREATE<SomeWindow>(shape, parent);
        GET<Window>(win).initLayout();

        return win;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/