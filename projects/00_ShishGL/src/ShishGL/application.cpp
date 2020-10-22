/*============================================================================*/
#include "ShishGL/engine.hpp"
#include "ShishGL/application.hpp"
#include "ShishGL/log.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowContainer& Application::root() {

    /* TODO: fix getting some params before initialization */
    static WindowContainer ROOT({Engine::getDisplayWidth(),
                                 Engine::getDisplayHeight()});
    return ROOT;
}

/*----------------------------------------------------------------------------*/

uint8_t Application::run(int* argc_ptr, char** argv) {

    Engine::initialize(argc_ptr, argv);

    const uint8_t status = Engine::enterMainLoop();

    Engine::terminate();

    return status;
}

/*============================================================================*/
