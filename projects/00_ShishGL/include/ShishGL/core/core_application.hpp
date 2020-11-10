/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <unordered_set>

#include "log.hpp"
#include "ShishGL/core/input/timer.hpp"
#include "ShishGL/core/engine/template_engine.hpp"
/*============================================================================*/
namespace ShishGL {

    class CoreApplication {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static uint8_t run();

        static bool terminate();

        static const Timer& getRunTimer() {
            return RunTimer();
        }

        virtual ~CoreApplication() = default;

    private:

        CoreApplication() = default;

        /*--------------------------------------------------------------------*/

        static bool is_initialized;

        static Timer& RunTimer() {
            static Timer RUN_TIMER;
            return RUN_TIMER;
        }

        /*--------------------------------------------------------------------*/

        friend class EventSystem;
        friend class ObjectManager;

    };

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
