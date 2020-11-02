/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <unordered_set>

#include "log.hpp"
#include "time.hpp"
#include "ShishGL/core/engine/modular_engine.hpp"
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
        static SomeObject* create(Args&&... args) {

            if (!is_initialized) {
                LogSystem::printError("Creating object when not initialized");
            }

            auto new_obj = new SomeObject(std::forward<Args>(args)...);

            ActiveObjects().insert(new_obj);

            return new_obj;
        }

        static void remove(Object* object);
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

        using ObjectSet = std::unordered_set<Object*>;

        static ObjectSet& ActiveObjects();

        friend EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
