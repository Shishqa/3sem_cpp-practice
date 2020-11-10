/*============================================================================*/
#include <SFML/Graphics.hpp>

#include "ShishGL/core/engine/sfml/engine.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

sf::Font& SfmlEngine::ActiveFont() {
    static sf::Font ACTIVE_FONT;
    return ACTIVE_FONT;
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::displayText(const std::string_view& str, size_t font_size,
                             const Vector2<double>& pos) {

    sf::Text display_text(sf::String(str.data()), ActiveFont(),
                          static_cast<unsigned int>(font_size));

    display_text.setFillColor(sf::Color{
        active_color.r,
        active_color.g,
        active_color.b,
        active_color.a
    });

    display_text.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                          static_cast<float>(pos.y)));

    canvas->draw(display_text);
}

/*============================================================================*/