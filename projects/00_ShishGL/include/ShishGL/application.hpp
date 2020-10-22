/*============================================================================*/
#ifndef SHISHGL_APPLICATION_HPP
#define SHISHGL_APPLICATION_HPP
/*============================================================================*/
#include <cstdint>

#include "ShishGL/window/window_container.hpp"
/*============================================================================*/
namespace ShishGL {

    class Application {
    public:

        static uint8_t run(int* argc_ptr, char* argv[]);

        template <typename SomeWindow, typename... Args>
        static SomeWindow* create(Args... args) {
            return root().attach<SomeWindow>(std::forward<Args>(args)...);
        }

        virtual ~Application() = default;

    private:

        Application() = default;

        static WindowContainer& root();

    };

}
/*============================================================================*/
#endif //SHISHGL_APPLICATION_HPP
/*============================================================================*/
