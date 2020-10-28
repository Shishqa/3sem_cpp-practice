/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <chrono>
#include <unordered_set>

#include "log.hpp"
#include "engine.hpp"
#include "event_system.hpp"
/*============================================================================*/
namespace ShishGL {

    using namespace std::chrono;

    class CoreApplication {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static uint8_t run();

        static bool terminate();

        template <typename SomeObject, typename... Args>
        static SomeObject* create(Args&&... args) {

            if (!initialized) {
                LogSystem::printError("Creating window when not initialized");
            }

            auto new_obj = new SomeObject(std::forward<Args>(args)...);

            ActiveObjects().insert(new_obj);

            return new_obj;
        }

        static const high_resolution_clock::time_point& getInitTime() {
            return InitTime();
        }

        virtual ~CoreApplication() = default;

    private:

        CoreApplication() = default;

        /*--------------------------------------------------------------------*/

        static bool initialized;

        static high_resolution_clock::time_point& InitTime() {
            static high_resolution_clock::time_point INIT_TIME;
            return INIT_TIME;
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
