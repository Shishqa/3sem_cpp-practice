/*============================================================================*/
#ifndef SHISHGL_ENGINE_HPP
#define SHISHGL_ENGINE_HPP
/*============================================================================*/

#include <cstddef>
#include <ctime>

#include "engines/GLUT/window_engine.hpp"
#include "engines/GLUT/graphic_engine.hpp"

#include "log.hpp"

/*============================================================================*/

namespace ShishGL {

    class Application;

    template <typename GraphicEngine, typename WindowEngine>
    class GEngine : public GraphicEngine, public WindowEngine {
    public:

        using WIN_ID = typename WindowEngine::WIN_ID;

        static void initialize(int* argc_ptr, char* argv[]) {

            init_time = time(nullptr);

            LogSystem::openLog();

            LogSystem::printLog("Initializing window engine...");
            WindowEngine::init(argc_ptr, argv);
            LogSystem::printLog("Window engine initialized");
        }

        static void terminate() {

            LogSystem::printLog("Terminating engine...");

            LogSystem::closeLog();

        }

        virtual ~GEngine() = default;

    private:

        GEngine() = default;

        static const Application* current_running_app;

        static time_t init_time;

        friend Application;
        friend LogSystem;
    };

    using Engine = GEngine<GlutGraphicEngine, GlutWindowEngine>;

}

/*============================================================================*/
#endif //SHISHGL_ENGINE_HPP
/*============================================================================*/
