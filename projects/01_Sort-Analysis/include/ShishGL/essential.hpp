#ifndef ESSENTIAL_HPP
#define ESSENTIAL_HPP

#include <cstdint>

namespace ShishGL {

    void init(int*argc_ptr, char**argv);

    void run();

    void terminate();

    struct Color {
        uint8_t r, g, b, a;
    };

    void fillWithColor(const Color& color);
}

#endif //ESSENTIAL_HPP
