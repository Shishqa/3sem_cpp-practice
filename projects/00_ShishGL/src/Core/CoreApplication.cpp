/*============================================================================*/
#include "Log.hpp"
#include "CoreApplication.hpp"
#include "iSystem.hpp"
#include "EventSystem.hpp"
#include "ColorCollection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool CoreApplication::is_initialized = false;

ISystem* CoreApplication::active_system = nullptr;

/*----------------------------------------------------------------------------*/

ISystem& CoreApplication::System() {
    return *active_system;
}

/*----------------------------------------------------------------------------*/

ISystem& SYSTEM() {
    return CoreApplication::System();
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    LogSystem::openLog();
    LogSystem::printLog("Initializing system...");

#ifdef USE_SFML
    active_system = new SfmlSystem();
    LogSystem::printLog("SFML System is now active");
#endif

    System().initDisplay(argc_ptr, argv);
    LogSystem::printLog("system initialized");

    is_initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

uint8_t CoreApplication::run() {

    if (!is_initialized) {
        LogSystem::printError("Running CoreApplication before initialization");
        return 1; /* todo */
    }

    EventSystem::EventTimer().reset();

    Timer frame_timer = {};
    frame_timer.reset();
    size_t frame_counter = 0;

    while (System().isRunning()) {

        ++frame_counter;

        System().clear(BLACK);
        //EventSystem::sendEvent<RenderEvent>(SystemEvents::RENDER);
        System().display();

        TimeDelta delta = frame_timer.elapsed();
        if (delta.count() > 1000000000LL) {
            printf("fps: %lu\n", frame_counter);
            frame_counter = 0;
            frame_timer.reset();
        }

        EventSystem::dispatchEvents();
    }

    terminate();

    return 0;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::terminate() {

    EventSystem::flush();

    LogSystem::printLog("terminating engine...");
    System().closeDisplay();
    LogSystem::printLog("engine terminated");

    LogSystem::closeLog();

    is_initialized = false;
    active_system = nullptr;

    return true;
}

/*============================================================================*/
