#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>


class Window {
public:

    Window() = delete;

    Window(const int& pos_x, const int& pos_y,
           const size_t& width, const size_t& height)
           : info({ID_UNDEFINED, pos_x, pos_y, width, height, }) {}

    virtual ~Window() {};

    virtual void set() = 0;

    struct WindowInfo {

        int id;

        int pos_x,
            pos_y;

        size_t width,
               height;

    };

    void setHandlers() {

        glutSetWindow(info.id);

        setCurrentWindow(this);
        glutDisplayFunc(glutOnRender);
        glutReshapeFunc(glutOnReshape);
        glutKeyboardFunc(glutOnKeyPress);
        glutMouseFunc(glutOnMouseClick);

    }

protected:

    WindowInfo info;

    std::vector<Window*> sub_windows;

    static const int ID_UNDEFINED = -1;
    static Window* current_window;

    static void setCurrentWindow(Window* win_ptr) {
        current_window = win_ptr;
    }

    //==========================================================================

    virtual void onRender() = 0;

    virtual void onReshape(int, int) = 0;

    virtual void onKeyPress(unsigned char, int, int) = 0;

    virtual void onMouseClick(int, int, int, int) = 0;

    //--------------------------------------------------------------------------

    static void glutOnRender() {
        if (current_window) {
            glutSetWindow(current_window->info.id);
            current_window->onRender();
        }
    };

    static void glutOnReshape(int width, int height) {
        if (current_window) {
            glutSetWindow(current_window->info.id);
            current_window->onReshape(width, height);
        }
    };

    static void glutOnKeyPress(unsigned char key, int x, int y) {
        if (current_window) {
            glutSetWindow(current_window->info.id);
            current_window->onKeyPress(key, x, y);
        }
    }

    static void glutOnMouseClick(int button, int state, int x, int y) {
        if (current_window) {
            glutSetWindow(current_window->info.id);
            current_window->onMouseClick(button, state, x, y);
        }
    }

    //==========================================================================

};

#endif //WINDOW_HPP
