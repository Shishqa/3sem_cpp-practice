#ifndef DRAW_HPP
#define DRAW_HPP


#include <cstdint>

#include "colors.hpp"


namespace ShishGL {

    struct Color {
        uint8_t r, g, b, a;
    };

    void fillWithColor(const Color& color);

    size_t displayText(const char* text, const Vector2<int>& position);

    void drawLine();

}


#endif //DRAW_HPP
