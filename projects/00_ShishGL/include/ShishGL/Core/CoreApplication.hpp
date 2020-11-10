/*============================================================================*/
#ifndef SHISHGL_CORE_APPLICATION_HPP
#define SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>
#include <unordered_set>

#include "ShishGL/Core/Log/Log.hpp"
#include "Primitives/Time.hpp"
#include "engine/template_engine.hpp"
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



        /*--------------------------------------------------------------------*/

        friend class EventSystem;
        friend class ObjectManager;

    };

}
/*============================================================================*/
#endif //SHISHGL_CORE_APPLICATION_HPP
/*============================================================================*/
