#ifndef DRAW_HPP
#define DRAW_HPP


#include <cstdint>
#include <cstddef>

#include "essential.hpp"
#include "colors.hpp"


namespace ShishGL {

    struct Color {
        uint8_t r, g, b, a;
    };

    void renderBegin(const Vector2<double>& viewport);
    void renderBegin(const Vector2<size_t>& viewport);

    void renderEnd();

    void fillWithColor(const Color& color);

    void setColor(const Color& color);

    size_t displayText(const char* text, const size_t& text_len,
                       const Vector2<int>& position,
                       const Color& color);

    void drawLine(const Vector2<double>& begin,
                  const Vector2<double>& end);

    void drawArrow(const Vector2<double>& begin,
                   const Vector2<double>& end);

}


#endif //DRAW_HPP
