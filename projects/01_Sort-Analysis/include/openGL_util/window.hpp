#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <stdexcept>
#include <functional>
#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>


class Window {
public:

    Window() = delete;

    Window(const int& pos_x, const int& pos_y,
           const size_t& width, const size_t& height)
           : info({ID_UNDEFINED, pos_x, pos_y, width, height}) {

        printf("window created\n");

    }

    virtual ~Window() {

        printf("window deleted\n");

        for (auto& window : sub_windows) {

            delete window;
        }

    };

    void attachSubWindow(Window* sub_window) {

        sub_windows.emplace_back(sub_window);

    }

    void dump() {

        printf("{ %d ", info.id);

        for (auto& window : sub_windows) {
            window->dump();
        }

        printf("}");

    }

    struct WindowInfo {

        int id;

        int pos_x,
            pos_y;

        size_t width,
               height;

    };

protected:

    void initSubWindowsLayout() {

        if (info.id == ID_UNDEFINED) {
            throw std::runtime_error("undefined window");
        }

        printf("subwindow layout for: %d\n", info.id);

        for (auto& window : sub_windows) {

            if (!window) {
                continue;
            }

            window->info.id = glutCreateSubWindow(info.id, window->info.pos_x,
                                                           window->info.pos_y,
                                                           window->info.width,
                                                           window->info.height);
            window->setHandlers();

            window->initSubWindowsLayout();
        }

        printf("done\n");

    }

    void setHandlers() {

        printf("setting handlers for: %d\n", info.id);
        glutSetWindow(info.id);

        setCurrentWindow(this);

        // TODO: STD::BIND!!!
        glutDisplayFunc(glutOnRender);
        glutReshapeFunc(glutOnReshape);
        glutKeyboardFunc(glutOnKeyPress);
        glutMouseFunc(glutOnMouseClick);

    }

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

//    //--------------------------------------------------------------------------
//
//    static void glutOnRender() {
//        if (current_window) {
//            glutSetWindow(current_window->info.id);
//
//            printf("calling onRender() for %d\n", current_window->info.id);
//            current_window->onRender();
//            printf("done onRender() for %d\n", current_window->info.id);
//        }
//    }
//
//    static void glutOnReshape(int width, int height) {
//        if (current_window) {
//            glutSetWindow(current_window->info.id);
//
//            printf("calling onReshape() for %d\n", current_window->info.id);
//            current_window->onReshape(width, height);
//            printf("done onReshape() for %d\n", current_window->info.id);
//        }
//    }
//
//    static void glutOnKeyPress(unsigned char key, int x, int y) {
//        if (current_window) {
//            glutSetWindow(current_window->info.id);
//
//            printf("calling onKeyPress() for %d\n", current_window->info.id);
//            current_window->onKeyPress(key, x, y);
//            printf("done onKeyPress() for %d\n", current_window->info.id);
//
//        }
//    }
//
//    static void glutOnMouseClick(int button, int state, int x, int y) {
//        if (current_window) {
//            glutSetWindow(current_window->info.id);
//
//            printf("calling onMouseClick() for %d\n", current_window->info.id);
//            current_window->onMouseClick(button, state, x, y);
//            printf("done onMouseClick() for %d\n", current_window->info.id);
//        }
//    }
//
//    //==========================================================================

};

#endif //WINDOW_HPP
