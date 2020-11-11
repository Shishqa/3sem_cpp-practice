/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <unordered_set>

#include "iSystem.hpp"
#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class CoreApplication {
    public:

        static constexpr Object::ID RENDER_EVENTS = 2;

        static bool init(int* argc_ptr, char* argv[]);

        static uint8_t run();

        static bool terminate();

        static ISystem& System();

        virtual ~CoreApplication() = default;

    private:

        CoreApplication() = default;

        /*--------------------------------------------------------------------*/

        static bool is_initialized;

        /*--------------------------------------------------------------------*/

        static ISystem* active_system;

    };

    ISystem& SYSTEM();

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
