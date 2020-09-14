#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <cstdio>
#include <cstddef>

#include <vector>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "window.hpp"


class Application : public Window {
public:

    Application(const char* title, const size_t& width, const size_t& height)
            : Window(0, 0, width, height)
            , title(title) {

        printf("app created\n");

    }

    virtual ~Application() {

        printf("app deleted\n");

    }

    void run(int* argc_ptr, char** argv) {

        init(argc_ptr, argv);

        initAppLayout();

        glutMainLoop();

    }

protected:

    void init(int* argc_ptr, char** argv) {

        printf("app init start\n");

        glutInit(argc_ptr, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

        glutInitContextVersion(3, 3);
        glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
        glutInitContextProfile(GLUT_CORE_PROFILE);

        printf("app init end\n");
    }

    void initAppLayout() {

        glutInitWindowPosition(info.pos_x, info.pos_y);
        glutInitWindowSize(info.width, info.height);
        info.id = glutCreateWindow(title);

        printf("Main window: %d\n", info.id);

        setHandlers();

        initSubWindowsLayout();

        printf("app layout set\n");

        dump();
        printf("\n");
    }

    const char* title;

};


#endif //APPLICATION_HPP
