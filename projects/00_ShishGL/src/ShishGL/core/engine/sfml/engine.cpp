/*============================================================================*/
#include "ShishGL/core/engine/sfml/engine.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

sf::RenderWindow* SfmlEngine::canvas = nullptr;

bool SfmlEngine::is_running = false;

/*----------------------------------------------------------------------------*/

bool SfmlEngine::initDisplay(int*, char**) {

    canvas = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "sfml",
                                  sf::Style::Fullscreen);

    /* todo: fix hard-coded font */
    if (!ActiveFont().loadFromFile("./FiraCode-Regular.ttf")) {
        return false;
    }

    is_running = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::isRunning() {
    return is_running;
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::closeDisplay() {

    is_running = false;

    delete canvas;
    canvas = nullptr;

    return true;
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::clear(const Color& color) {
    canvas->clear(sf::Color{color.r, color.g, color.b, color.a});
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::render() {
    canvas->display();
}

/*============================================================================*/

Vector2<size_t> SfmlEngine::getDisplaySize() {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    return Vector2<size_t>{screen.width, screen.height};
}

/*----------------------------------------------------------------------------*/

Vector2<double> SfmlEngine::getMousePos() {
    return Vector2<double>{
        static_cast<double>(sf::Mouse::getPosition(*canvas).x),
        static_cast<double>(sf::Mouse::getPosition(*canvas).y)
    };
}

/*============================================================================*/
