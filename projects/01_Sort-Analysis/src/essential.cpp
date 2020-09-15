#include <cstdio>
#include <stdexcept>

#include <GL/freeglut.h>
#include <GL/gl.h>

#include "essential.hpp"
#include "log.hpp"


void ShishGL::init(int*argc_ptr, char**argv, uint8_t flags) {

    if (flags & DEBUG) {
        do_log = true;
        if (openLog()) {
            throw std::runtime_error("Error: failed to open log file!\n");
        }
    }

    printLog("ShishGL initialization started\n");

    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    printLog("ShishGL initialized\n");
}


void ShishGL::terminate() {

    printLog("Terminating ShishGL\n");

    closeLog();

}
