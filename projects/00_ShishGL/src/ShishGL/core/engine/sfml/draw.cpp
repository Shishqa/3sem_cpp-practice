/*============================================================================*/
#include <GL/freeglut.h>

#include "ShishGL/core/engine/sfml/engine.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Color SfmlEngine::active_color = {};

/*----------------------------------------------------------------------------*/

void SfmlEngine::setColor(const Color& color) {
    active_color = color;
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::drawRectangle(const Vector2<int>& pos,
                               const Vector2<size_t>& size) {

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f{
        static_cast<float>(size.x),
        static_cast<float>(size.y)
    });

    rectangle.setPosition(sf::Vector2f{
        static_cast<float>(pos.x),
        static_cast<float>(pos.y)
    });

    rectangle.setFillColor(sf::Color{
        active_color.r,
        active_color.g,
        active_color.b,
        active_color.a
    });

    canvas->draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::drawCircle(const Vector2<int>& pos, const size_t& radius) {

    sf::CircleShape circle;

    circle.setPosition(sf::Vector2f{
            static_cast<float>(pos.x),
            static_cast<float>(pos.y)
    });

    circle.setRadius(static_cast<float>(radius));

    canvas->draw(circle);
}

/*============================================================================*/
