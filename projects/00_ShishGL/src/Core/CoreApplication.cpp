/*============================================================================*/
#include "Log.hpp"
#include "CoreApplication.hpp"
#include "System.hpp"
#include "EventSystem.hpp"
#include "GraphicObject.hpp"
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
    LogSystem::printLog("System initialized");

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

    while (System().isRunning()) {

        System().pollEvent();
        EventSystem::dispatchAll();

        if (!System().isRunning()) {
            break;
        }

        ++frame_counter;

        System().clear(Color{0, 0, 0, 255});
        EventSystem::sendEvent<RenderEvent>(RENDER_EVENTS);
        System().display();

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

    LogSystem::printLog("Terminating system...");
    EventManager::flush();
    ObjectManager::clear();

    System().closeDisplay();
    delete active_system;
    active_system = nullptr;
    LogSystem::printLog("System terminated");

    LogSystem::closeLog();
    is_initialized = false;

    return true;
}

/*============================================================================*/
