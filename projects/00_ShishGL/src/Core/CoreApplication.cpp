/*============================================================================*/
#include "LogSystem.hpp"
#include "EventSystem.hpp"
#include "RenderSystem.hpp"
#include "CoreApplication.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool CoreApplication::is_initialized = false;

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    LogSystem::openLog();
    LogSystem::printLog("Initializing RenderSystem...");

    RenderSystem::init(argc_ptr, argv);

    LogSystem::printLog("RenderSystem initialized");

    is_initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

uint8_t CoreApplication::run() {

    if (!is_initialized) {
        LogSystem::printError("Running CoreApplication before initialization");
        return 10;
    }

    Timer frame_timer = {};
    frame_timer.reset();
    size_t frame_counter = 0;

    LogSystem::printLog("Started run session");

    while (RENDERER().isRunning()) {

        RENDERER().pollEvent();
        EventSystem::dispatchAll();
        if (!RENDERER().isRunning()) {
            break;
        }

        ++frame_counter;

        RenderSystem::update();

        TimeDelta delta = frame_timer.elapsed();
        if (delta.count() > 1000000000LL) {
            printf("fps: %lu\n", frame_counter);
            frame_counter = 0;
            frame_timer.reset();
        }
    }

    terminate();

    return 0;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::terminate() {

    LogSystem::printLog("Terminating Core...");
    EventManager::flush();
    ObjectManager::clear();
    RenderSystem::terminate();
    LogSystem::printLog("Core terminated");

    LogSystem::closeLog();
    is_initialized = false;

    return true;
}

/*============================================================================*/
