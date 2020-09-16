#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstdio>
#include <stdexcept>
#include <vector>
#include <queue>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "essential.hpp"


namespace ShishGL {

    class Window {
    public:

        Window() = delete;

        Window(const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height);

        Window(const Window& other);

        Window(Window&& other);

        Window& operator=(const Window& other);

        Window& operator=(Window&& other);

        virtual ~Window();

        void dump();

        struct WindowInfo {

            int id;

            int pos_x, pos_y;

            size_t width, height;

        };

        void attach(Window* window);

    protected:

        WindowInfo info;

        static const int ID_UNDEFINED = 0;

        std::vector<Window*> subwindows;

        //==========================================================================

        virtual void onIdle() { }

        virtual void onRender() { }

        virtual void onEntry(int) { }

        virtual void onReshape(int, int) { }

        virtual void onKeyPress(unsigned char, int, int) { }

        virtual void onMouseClick(int, int, int, int) { }

        //==========================================================================

        static const int MAX_ALLOWED_WINDOW_CNT = 200;
        static Window* active_windows[MAX_ALLOWED_WINDOW_CNT + 1];

        static void makeActive(Window* window);

        static Window* getCurrentActiveWindow();

        static void manageOnIdle();

        static void manageOnRender();

        static void manageOnEntry(int state);

        static void manageOnReshape(int width, int height);

        static void manageOnKeyPress(unsigned char key, int x, int y);

        static void manageOnMouseClick(int button, int state, int x, int y);

        //==========================================================================

    };

}

#endif //WINDOW_HPP
