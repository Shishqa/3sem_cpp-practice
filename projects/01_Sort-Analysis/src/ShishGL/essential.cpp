#include <stdexcept>


#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>


#include "ShishGL/essential.hpp"
#include "ShishGL/log.hpp"


int ShishGL::init(int* argc_ptr, char** argv) {

#ifdef DEBUG
    if (!openLog()) {
        throw std::runtime_error("Error: failed to open log file!");
    }
#endif

    printLog("ShishGL initialization started");

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    printLog("ShishGL initialized");

    return 0;
}


int ShishGL::enterMainLoop() {
    glutMainLoop();
    return 0;
}


void ShishGL::terminate() {

    printLog("Terminating ShishGL");

#ifdef DEBUG
    closeLog();
#endif

}
