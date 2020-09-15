#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <cstdio>
#include <cstddef>

#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "window.hpp"

namespace ShishGL {

    class Application : public Window {
    public:

        Application(const char*title, const size_t& width, const size_t& height)
                : Window(0, 0, width, height), title(title) {

            printf("app created\n");

        }

        virtual ~Application() {

            printf("app deleted\n");

        }

        void run(int*argc_ptr, char**argv) {

            init(argc_ptr, argv);

            glutMainLoop();

        }

    protected:

        void init(int*argc_ptr, char**argv) {

            printf("app init start\n");



            glutInitWindowPosition(info.pos_x, info.pos_y);
            glutInitWindowSize(info.width, info.height);
            info.id = glutCreateWindow(title);

            initLayout(this);

            printf("app init end\n");
        }

        static void initLayout(Window*window) {

            window->setHandlers();

            for (auto& sub_window : window->sub_windows) {

                initLayout(sub_window);

            }
        }

        const char*title;

    };

}

#endif //APPLICATION_HPP
