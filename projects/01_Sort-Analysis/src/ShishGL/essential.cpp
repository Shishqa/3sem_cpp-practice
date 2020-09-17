#include <stdexcept>


#include <GL/glew.h>
#include <GL/freeglut.h>


#include "ShishGL/essential.hpp"
#include "ShishGL/log.hpp"


void ShishGL::init(int* argc_ptr, char** argv) {

#ifdef DEBUG
    do_log = true;
    if (!openLog()) {
        throw std::runtime_error("Error: failed to open log file!");
    }
#endif

    printLog("ShishGL initialization started");

    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    printLog("ShishGL initialized");
}


void ShishGL::run() {

    glutMainLoop();
}


void ShishGL::terminate() {

    printLog("Terminating ShishGL");

#ifdef DEBUG
    closeLog();
#endif

}


void ShishGL::fillWithColor(const Color& color) {

    glClearColor(static_cast<float>(color.r) / 255.f,
                 static_cast<float>(color.g) / 255.f,
                 static_cast<float>(color.b) / 255.f,
                 static_cast<float>(color.a) / 255.f);
    glClear(GL_COLOR_BUFFER_BIT);

}

