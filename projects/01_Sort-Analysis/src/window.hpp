#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstdio>
#include <stdexcept>
#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "essential.hpp"


namespace ShishGL {

    class Window {
    public:

        Window() = delete;

        Window(const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height);

        virtual ~Window();

        void attachSubWindow(Window* window);

        void dump();

        struct WindowInfo {

            int id;

            int pos_x, pos_y;

            size_t width, height;

        };

    protected:

        void setHandlers() {

            glutSetWindow(window->info.id);

            glutDisplayFunc(glutOnRender);
            glutReshapeFunc(glutOnReshape);
            glutKeyboardFunc(glutOnKeyPress);
            glutMouseFunc(glutOnMouseClick);

        }

        WindowInfo info;

        std::vector<Window*> sub_windows;

        static const int ID_UNDEFINED = 0;

        static std::vector<Window*> active_windows;

        static void makeActive(Window* window);

        //==========================================================================

        virtual void onRender() = 0;

        virtual void onReshape(int, int) = 0;

        virtual void onKeyPress(unsigned char, int, int) = 0;

        virtual void onMouseClick(int, int, int, int) = 0;

        //--------------------------------------------------------------------------

        static void glutOnRender() {
            Window* win_ptr = active_windows.at(glutGetWindow());
            if (win_ptr) {
                win_ptr->onRender();
            }
        }

        static void glutOnReshape(int width, int height) {
            Window* win_ptr = active_windows.at(glutGetWindow());
            if (win_ptr) {
                win_ptr->onReshape(width, height);
            }
        }

        static void glutOnKeyPress(unsigned char key, int x, int y) {
            Window* win_ptr = active_windows.at(glutGetWindow());
            if (win_ptr) {
                win_ptr->onKeyPress(key, x, y);
            }
        }

        static void glutOnMouseClick(int button, int state, int x, int y) {
            Window* win_ptr = active_windows.at(glutGetWindow());
            if (win_ptr) {
                win_ptr->onMouseClick(button, state, x, y);
            }
        }

        //==========================================================================

    };

}

#endif //WINDOW_HPP
