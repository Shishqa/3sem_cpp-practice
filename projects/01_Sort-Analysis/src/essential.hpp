#ifndef ESSENTIAL_HPP
#define ESSENTIAL_HPP

#include <cstdint>

namespace ShishGL {

    enum INIT_FLAGS {
        DEBUG = 0b1
    };

    void init(int*argc_ptr, char**argv, uint8_t flags);

    void run();

    void terminate();

    struct Color {
        uint8_t r, g, b, a;
    };

}

#endif //ESSENTIAL_HPP
