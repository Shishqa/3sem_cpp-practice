/*============================================================================*/
#ifndef SHISHGL_ENGINE_HPP
#define SHISHGL_ENGINE_HPP
/*============================================================================*/
#include <cstddef>
#include <ctime>

#include "ShishGL/engines/glut/base.hpp"
#include "ShishGL/log.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename GraphicEngine>
    class GEngine : public GraphicEngine {
    private:

        /*--------------------------------------------------------------------*/
        /* initialization */
        static void initialize(int* argc_ptr, char* argv[]) {

            setInitTime(time(nullptr));

            LogSystem::openLog();

            LogSystem::printLog("Initializing engine...");
            GraphicEngine::initialize(argc_ptr, argv);
            LogSystem::printLog("Engine initialized");

        }
        /*--------------------------------------------------------------------*/
        /* termination */
        static void terminate() {

            LogSystem::printLog("Terminating engine...");
            GraphicEngine::terminate();
            LogSystem::printLog("Engine terminated");

            LogSystem::closeLog();

        }
        /*--------------------------------------------------------------------*/

        GEngine() = default;

        /* time of engine initialization */
        /*--------------------------------------------------------------------*/
        static time_t init_time;
        /*--------------------------------------------------------------------*/

        static void setInitTime(const time_t& time) { init_time = time; }

        friend class Application;

    public:

        [[nodiscard]]
        static const time_t& getInitTime() { return init_time; }

        virtual ~GEngine() = default;

    };

    template <typename GraphicEngine>
    time_t GEngine<GraphicEngine>::init_time = 0;

    /*========================================================================*/
    using Engine = GEngine<GlutEngine>;
    /*========================================================================*/

}
/*============================================================================*/
#endif //SHISHGL_ENGINE_HPP
/*============================================================================*/
