/*============================================================================*/
#include "ShishGL/core/object/object_manager.hpp"
#include "ShishGL/core/input/timer.hpp"
#include "ShishGL/core/engine/engine.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/core_application.hpp"
#include "ShishGL/core/event_system.hpp"
#include "ShishGL/color/color_collection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool CoreApplication::is_initialized = false;

CoreApplication::ObjectSet& CoreApplication::ActiveObjects() {
    static ObjectSet ACTIVE_OBJECTS;
    return ACTIVE_OBJECTS;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    LogSystem::openLog();

    RunTimer().reset();

    LogSystem::printLog("initializing engine...");
    Engine::initDisplay(argc_ptr, argv);
    LogSystem::printLog("engine initialized");

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

    while (Engine::isRunning()) {

        Engine::clear(BLACK);

        for (const auto& obj : ActiveObjects()) {
            EventSystem::sendEvent<Event>(obj, Event::RENDER);
        }

        Engine::render();

        EventSystem::dispatchEvents();
    }

    terminate();

    return 0;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::terminate() {

    EventSystem::flush();

    for (const auto& obj : ActiveObjects()) {
        ObjectManager::remove(obj);
    }

    LogSystem::printLog("terminating engine...");
    Engine::closeDisplay();
    LogSystem::printLog("engine terminated");

    LogSystem::closeLog();

    is_initialized = false;

    return true;
}

/*----------------------------------------------------------------------------*/

void CoreApplication::remove(Object::ID id) {
    ActiveObjects().erase(id);
    ObjectManager::remove(id);
}

/*============================================================================*/
