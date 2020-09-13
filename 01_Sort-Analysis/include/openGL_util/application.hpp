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
            , title(title) { }

    virtual ~Application() { }

    void init(int* argc_ptr, char** argv) {

        printf("app init start\n");

        glutInit(argc_ptr, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

        glutInitContextVersion(3, 3);
        glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
        glutInitContextProfile(GLUT_CORE_PROFILE);

        initWindowLayout();

        printf("app init end\n");
    }

    virtual void set() override {
        glutInitWindowSize(info.width, info.height);
        info.id = glutCreateWindow(title);
    }

    void run() {

        setAppHandlers();

        glutMainLoop();

    }

protected:

    void initWindowLayout() {

        set();

        for (auto& window: sub_windows) {
            window->set();
        }
    }

    void setAppHandlers() {

        setHandlers();

        for (auto& window : sub_windows) {
            window->setHandlers();
        }

    }

    const char* title;



//    virtual void onRender() override {};
//
//    virtual void onReshape(int, int) override {};
//
//    virtual void onKeyPress(unsigned char, int, int) override {};
//
//    virtual void onMouseClick(int, int, int, int) override {};


};


#endif //APPLICATION_HPP
