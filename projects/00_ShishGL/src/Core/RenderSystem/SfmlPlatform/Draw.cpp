/*============================================================================*/
#include "LogSystem.hpp"
#include "Platform.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void SfmlPlatform::setViewport(const Vector2<double>& pos,
                               const Vector2<double>& size,
                               const Vector2<double>& dp_pos,
                               const Vector2<double>& dp_size) {

    sf::View view(sf::FloatRect{
            static_cast<float>(pos.x),
            static_cast<float>(pos.y),
            static_cast<float>(size.x),
            static_cast<float>(size.y)
    });

    view.setViewport(sf::FloatRect{
            static_cast<float>(dp_pos.x),
            static_cast<float>(dp_pos.y),
            static_cast<float>(dp_size.x),
            static_cast<float>(dp_size.y)
    });

    canvas->setView(view);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setColor(const Color& color) {
    active_color = color;
    active_texture = nullptr;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setTexture(const ResourceManager::Resource& texture) {

    if (textures.count(texture.filename)) {
        active_texture = textures[texture.filename];
        return;
    }

    printf("SFML LOADING!!!!\n");

    auto sf_texture = new sf::Texture;
    sf_texture->loadFromMemory(texture.data, texture.size);

    textures[texture.filename] = sf_texture;
    active_texture = sf_texture;
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

    if (active_texture) {

        rectangle.setTexture(active_texture);

    } else {

        rectangle.setFillColor(sf::Color{
                active_color.r,
                active_color.g,
                active_color.b,
                active_color.a
        });
    }

    canvas->draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::drawCircle(const Vector2<double>& pos,
                            const double& radius) {

    sf::CircleShape circle;

    circle.setPosition(sf::Vector2f(static_cast<float>(pos.x),
                                    static_cast<float>(pos.y)));
    circle.setRadius(static_cast<float>(radius));

    if (active_texture) {

        circle.setTexture(active_texture);

    } else {

        circle.setFillColor(sf::Color{
                active_color.r,
                active_color.g,
                active_color.b,
                active_color.a
        });
    }

    canvas->draw(circle);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayImage(const ResourceManager::Resource& image,
                                const Vector2<double>& pos) {

    sf::Texture texture = {};
    texture.loadFromMemory(image.data, image.size);

    sf::Sprite sprite = {};
    sprite.setPosition(static_cast<float>(pos.x),
                       static_cast<float>(pos.y));

    sprite.setTexture(texture);
    canvas->draw(sprite);
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::setFont(const ResourceManager::Resource& font) {

    if (fonts.count(font.filename)) {
        active_font = fonts[font.filename];
        return;
    }

    auto sf_font = new sf::Font;
    sf_font->loadFromMemory(font.data, font.size);

    fonts[font.filename] = sf_font;
    active_font = sf_font;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::displayText(const ResourceManager::Resource& text,
                               const size_t& font_size,
                               const Vector2<double>& pos) {

    if (!active_font) {
        return;
    }

    sf::Text display_text(sf::String{reinterpret_cast<char*>(text.data)},
                          *active_font, static_cast<unsigned int>(font_size));

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
