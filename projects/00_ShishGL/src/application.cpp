/*============================================================================*/

#include "engine.hpp"
#include "application.hpp"
#include "log.hpp"

/*----------------------------------------------------------------------------*/

using namespace ShishGL;

/*============================================================================*/

Application::Application()
        : WindowContainer(Vector2<size_t>{0, 0}) {}

/*----------------------------------------------------------------------------*/

uint8_t Application::run(int* argc_ptr, char* argv[]) {

    Engine::initialize(argc_ptr, argv);

    Engine::current_running_app = this;
    LogSystem::printLog("Current running application is %p",
                        reinterpret_cast<void*>(this));

    for (auto& win_p : subwindows) {
        win_p->display();
    }

    Engine::enterMainLoop();

    for (auto& win_p : subwindows) {
        win_p->close();
    }

    Engine::terminate();
    return 0;
}

/*============================================================================*/
