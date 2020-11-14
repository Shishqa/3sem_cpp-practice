/*============================================================================*/
#ifndef SHISHGL_WINDOW_MANAGER_HPP
#define SHISHGL_WINDOW_MANAGER_HPP
/*============================================================================*/
#include "Window.hpp"
#include "ObjectManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class WindowManager {
    private:

        template <typename SomeWindow, typename T>
        using WindowHelper =
        std::enable_if_t<std::is_base_of<Window, SomeWindow>::value, T>;

    public:

        template <typename SomeWindow, typename SomeShape, typename... Args>
        static Object::ID create(Object::ID parent, Args&&... args);

        template <typename SomeWindow, typename SomeShape, typename... Args>
        static Object::ID create(Args&&... args);

    };

}
/*============================================================================*/
#include "WindowManager.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_MANAGER_HPP
/*============================================================================*/
