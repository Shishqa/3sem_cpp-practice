/*============================================================================*/
#ifndef SHISHGL_APPLICATION_HPP
#define SHISHGL_APPLICATION_HPP
/*============================================================================*/

#include <cstdint>
#include <ctime>

#include "window_container.hpp"

/*============================================================================*/

namespace ShishGL {

    class Application : protected WindowContainer {
    public:

        Application();

        ~Application() override = default;

        uint8_t run(int* argc_ptr, char* argv[]);

    };

}

/*============================================================================*/
#endif //SHISHGL_APPLICATION_HPP
/*============================================================================*/
