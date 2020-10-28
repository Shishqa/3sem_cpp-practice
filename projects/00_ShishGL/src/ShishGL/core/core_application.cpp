/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/core_application.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool CoreApplication::initialized = false;

WindowContainer& CoreApplication::Root() {
    static WindowContainer ROOT(nullptr);
    return ROOT;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (initialized) {
        return false;
    }

    LogSystem::openLog();

    LogSystem::printLog("initializing engine...");
    Engine::initialize(argc_ptr, argv);
    LogSystem::printLog("engine initialized");

    initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

uint8_t CoreApplication::run() {

    if (!initialized) {
        return 1; /* todo */
    }

    while (EventSystem::dispatchEvents()) {
        Engine::clear();

        EventSystem::sendEvent<EmptyEvent>(
                reinterpret_cast<Object*>(&Root()),
                Event::RENDER
                );

        Engine::display();
    }

    LogSystem::printLog("terminating engine...");
    Engine::terminate();
    LogSystem::printLog("engine terminated");

    LogSystem::closeLog();

    initialized = false;

    return 0;
}

/*============================================================================*/
