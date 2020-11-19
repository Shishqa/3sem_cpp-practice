/*============================================================================*/
#include "LogSystem.hpp"
#include "Platform.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void SfmlPlatform::setViewport(const Vector2<double>& pos,
                               const Vector2<double>& size) {

    sf::View view(sf::FloatRect{
            static_cast<float>(pos.x),
            static_cast<float>(pos.y),
            static_cast<float>(size.x),
            static_cast<float>(size.y)
    });

    view.setViewport(sf::FloatRect{
            static_cast<float>(pos.x / static_cast<double>(getDisplaySize().x)),
            static_cast<float>(pos.y / static_cast<double>(getDisplaySize().y)),
            static_cast<float>(size.x / static_cast<double>(getDisplaySize().x)),
            static_cast<float>(size.y / static_cast<double>(getDisplaySize().y))
    });

    canvas->setView(view);

    //printf("setting viewport at (%lg; %lg) %lgx%lgpx\n",
    //       pos.x, pos.y, size.x, size.y);

}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setColor(const Color& color) {
    active_color = color;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawPoint(const Vector2<double>& pos) {

    sf::VertexArray point(sf::Points, 1);

    point[0].position = sf::Vector2f(static_cast<float>(pos.x),
                                     static_cast<float>(pos.y));
    point[0].color = sf::Color(active_color.r,
                               active_color.g,
                               active_color.b,
                               active_color.a);

    canvas->draw(point);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawLine(const Vector2<double>& start,
                          const Vector2<double>& end) {

    sf::VertexArray line(sf::LineStrip, 2);

    line[0].position = sf::Vector2f(static_cast<float>(start.x),
                                    static_cast<float>(start.y));
    line[0].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    line[1].position = sf::Vector2f(static_cast<float>(end.x),
                                    static_cast<float>(end.y));
    line[1].color = sf::Color(active_color.r,
                              active_color.g,
                              active_color.b,
                              active_color.a);

    canvas->draw(line);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawRectangle(const Vector2<double>& pos,
                               const Vector2<double>& size) {

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(static_cast<float>(size.x),
                                   static_cast<float>(size.y)));
    rectangle.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                       static_cast<float>(pos.y)));
    rectangle.setFillColor(sf::Color{
        active_color.r,
        active_color.g,
        active_color.b,
        active_color.a
    });

    canvas->draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawCircle(const Vector2<double>& pos,
                            const double& radius) {

    sf::CircleShape circle;

    circle.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                    static_cast<float>(pos.y)));
    circle.setRadius(static_cast<float>(radius));

    circle.setFillColor(sf::Color{
            active_color.r,
            active_color.g,
            active_color.b,
            active_color.a
    });

    canvas->draw(circle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayImage(const uint8_t* data, const size_t& data_size,
                              const Vector2<double>& pos) {

    sf::Texture texture = {};

    texture.loadFromMemory(data, data_size);

    sf::Sprite sprite = {};

    sprite.setPosition(static_cast<float>(pos.x),
                       static_cast<float>(pos.y));

    sprite.setTexture(texture);

    canvas->draw(sprite);

}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayText(const std::string_view& str, size_t font_size,
                             const Vector2<double>& pos) {

    sf::Text display_text(sf::String(str.data()), active_font,
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
