/*============================================================================*/
#include "System.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SfmlSystem::SfmlSystem()
    : is_running(false)
    , canvas(nullptr)
    , active_color({})
    , active_font({})
    { }

/*----------------------------------------------------------------------------*/

bool SfmlSystem::initDisplay(int*, char**) {

    canvas = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "sfml",
                                  sf::Style::Fullscreen);

    canvas->setMouseCursorVisible(false);

    /* todo: fix hard-coded font */
    if (!active_font.loadFromFile("./FiraCode-Regular.ttf")) {
        return false;
    }

    is_running = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool SfmlSystem::isRunning() {
    return is_running;
}

/*----------------------------------------------------------------------------*/

bool SfmlSystem::closeDisplay() {

    is_running = false;

    delete canvas;
    canvas = nullptr;

    return true;
}

/*----------------------------------------------------------------------------*/

void SfmlSystem::clear(const Color& color) {
    canvas->clear(sf::Color{color.r, color.g, color.b, color.a});
}

/*----------------------------------------------------------------------------*/

void SfmlSystem::display() {
    canvas->display();
}

/*============================================================================*/

Vector2<size_t> SfmlSystem::getDisplaySize() {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    return Vector2<size_t>{screen.width, screen.height};
}

/*----------------------------------------------------------------------------*/

Vector2<double> SfmlSystem::getMousePos() {
    return Vector2<double>{
        static_cast<double>(sf::Mouse::getPosition(*canvas).x),
        static_cast<double>(sf::Mouse::getPosition(*canvas).y)
    };
}

/*============================================================================*/
