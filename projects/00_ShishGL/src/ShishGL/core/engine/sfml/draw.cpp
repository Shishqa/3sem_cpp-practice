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

void SfmlEngine::drawPoint(const Vector2<double>& pos) {

    sf::VertexArray point(sf::Points, 1);

    point[0].position = sf::Vector2f(pos.x, pos.y);
    point[0].color = sf::Color(active_color.r,
                               active_color.g,
                               active_color.b,
                               active_color.a);

    canvas->draw(point);
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::drawLine(const Vector2<double>& start,
                          const Vector2<double>& end) {

    sf::VertexArray line(sf::LineStrip, 2);

    line[0].position = sf::Vector2f(start.x, start.y);
    line[0].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    line[1].position = sf::Vector2f(end.x, end.y);
    line[1].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    canvas->draw(line);
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::drawRectangle(const Vector2<double>& pos,
                               const Vector2<double>& size) {

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(size.x, size.y));
    rectangle.setPosition(sf::Vector2f(pos.x, pos.y));
    rectangle.setFillColor(sf::Color{
        active_color.r,
        active_color.g,
        active_color.b,
        active_color.a
    });

    canvas->draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::drawCircle(const Vector2<double>& pos,
                            const size_t& radius) {

    sf::CircleShape circle;

    circle.setPosition(sf::Vector2f(pos.x, pos.y));
    circle.setRadius(static_cast<float>(radius));

    canvas->draw(circle);
}

/*============================================================================*/
