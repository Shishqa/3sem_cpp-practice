/*============================================================================*/
#include "ShishGL/core/object/object_manager.hpp"
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/core/engine/engine.hpp"
#include "ShishGL/Core/Log/Log.hpp"
#include "ShishGL/Core/CoreApplication.hpp"
#include "ShishGL/Core/Event/EventSystem.hpp"
#include "ShishGL/core/event/system_slots.hpp"
#include "ShishGL/Core/Platform/ColorCollection.hpp"
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

    Timer frame_timer = {};
    frame_timer.reset();
    size_t frame_counter = 0;

    while (Engine::isRunning()) {

        ++frame_counter;

        Engine::clear(BLACK);
        EventSystem::sendEvent<RenderEvent>(SystemEvents::RENDER);
        Engine::render();

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
    Engine::closeDisplay();
    LogSystem::printLog("engine terminated");

    LogSystem::closeLog();

    is_initialized = false;

    return true;
}

/*============================================================================*/
