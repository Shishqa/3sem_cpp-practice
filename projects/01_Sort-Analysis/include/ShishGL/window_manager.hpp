#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include "window.hpp"

#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

namespace ShishGL {

    class WindowManager {
    public:

        static int initialize();

    private:

        static Display* display;

        WindowManager() = default;

        ~WindowManager() = default;

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        friend Window;

        static void makeActive(Window* window);

        static void makeInactive(Window* window);

        static Window* getCurrentActiveWindow();

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        using WindowMap = std::unordered_map<int, Window*>;

        static WindowMap& ActiveWindows();

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        static void setHandlers(Window* window);

        static void activate(Window* window);

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        static void manageOnIdle();

        static void manageOnRender();

        static void manageOnEntry(int state);

        static void manageOnReshape(int width, int height);

        static void manageOnKeyPress(unsigned char key, int x, int y);

        static void manageOnMouseClick(int button, int state, int x, int y);
    };

}

#endif //WINDOW_MANAGER_HPP
