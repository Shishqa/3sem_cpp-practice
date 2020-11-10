/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <unordered_set>

#include "log.hpp"
#include "ShishGL/core/input/timer.hpp"
#include "ShishGL/core/engine/template_engine.hpp"
#include "event_system.hpp"
/*============================================================================*/
namespace ShishGL {

    class CoreApplication {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static uint8_t run();

        static bool terminate();

        /*--------------------------------------------------------------------*/
        template <typename SomeObject, typename... Args>
        static Object::ID create(Args&&... args) {

            if (!is_initialized) {
                LogSystem::printError("Creating window when not initialized");
            }

            Object::ID id =
                    ObjectManager::create<SomeObject>(std::forward<Args>(args)...);

            return id;
        }

        static void remove(Object::ID id);
        /*--------------------------------------------------------------------*/

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

        friend EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
