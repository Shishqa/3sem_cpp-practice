/*============================================================================*/
#ifndef SHISHGL_WINDOW_MANAGER_HPP
#define SHISHGL_WINDOW_MANAGER_HPP
/*============================================================================*/
#include <unordered_set>

#include "window_container.hpp"
/*============================================================================*/
namespace ShishGL {

    class WindowManager {
    public:

        friend class Application;
        friend Window;

        ~WindowManager() = default;

    private:

        WindowManager() = default;

        static void makeActive(Window* window);

        static void makeInactive(Window* window);

        /*--------------------------------------------------------------------*/
        static WindowContainer::WindowSet& ActiveWindows();
        /*--------------------------------------------------------------------*/

    };

    /*------------------------------------------------------------------------*/

    class WindowRenderer {
    public:

        static void render(Window* window);

        virtual ~WindowRenderer() = default;

    private:

        WindowRenderer() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_MANAGER_HPP
/*============================================================================*/
