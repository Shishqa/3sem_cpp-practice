/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <chrono>

#include "engine.hpp"
#include "event_system.hpp"
#include "window_container.hpp"
/*============================================================================*/
namespace ShishGL {

    using namespace std::chrono;

    class CoreApplication {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static uint8_t run();

        template <typename SomeWindow, typename... Args>
        static SomeWindow* create(Args... args) {
            return Root().attach<SomeWindow>(nullptr, std::forward<Args>(args)...);
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

        static WindowContainer& Root();

        friend EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
