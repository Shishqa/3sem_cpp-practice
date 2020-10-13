#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include "window.hpp"

namespace ShishGL {

    class WindowManager {
    public:

        ~WindowManager() = default;

    private:

        WindowManager() = default;

        friend Window;

        static void makeActive(Window* window);

        static void makeInactive(Window* window);

        static Window* getCurrentActiveWindow();

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        using WindowMap = std::unordered_map<GI::WIN_ID, Window*>;

        static WindowMap& ActiveWindows();

        static void activate(Window* window);

    };

}

#endif //WINDOW_MANAGER_HPP
