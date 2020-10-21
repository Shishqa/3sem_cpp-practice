/*============================================================================*/

#include <stdexcept>

/*----------------------------------------------------------------------------*/

#include "ShishGL/engines/graphic_interface.hpp"
#include "ShishGL/application.hpp"
#include "ShishGL/log.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

void Application::init(int* argc_ptr, char** argv) {

    GraphicBase::init(argc_ptr, argv);

#ifdef LOG
    if (!openLog()) {
        throw std::runtime_error("Error: failed to open log file!");
    }
#endif

    printLog("Application initialized");
}

/*----------------------------------------------------------------------------*/

uint8_t Application::run() {
    printLog("Entering main loop");
    GraphicBase::enterMainLoop();

    for (const auto& win_p : RootWindows()) {
        delete win_p;
    }

    printLog("Application terminated");
    closeLog();

    return 0;
}

/*----------------------------------------------------------------------------*/

Application::WindowSet& Application::RootWindows() {

    static WindowSet ROOT_WINDOWS;
    return ROOT_WINDOWS;

}

/*============================================================================*/
