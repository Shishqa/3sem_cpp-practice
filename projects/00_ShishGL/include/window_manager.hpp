#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <unordered_map>
#include <unordered_set>

#include "window.hpp"


namespace ShishGL {

    class Application;

    class WindowManager {
    public:

        friend Application;
        friend Window;

        ~WindowManager() = default;

    private:

        WindowManager() = default;

        static void makeActive(Window* window);

        static void makeInactive(Window* window);

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        using WindowMap = std::unordered_map<GraphicBase::WIN_ID, Window*>;

        static WindowMap& ActiveWindows();

        static void activate(Window* window);

    };

}

#endif //WINDOW_MANAGER_HPP
