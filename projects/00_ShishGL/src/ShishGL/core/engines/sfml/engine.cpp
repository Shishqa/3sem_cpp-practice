/*============================================================================*/
#include <cassert>

#include "ShishGL/core/engines/sfml/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

sf::RenderWindow* SfmlEngine::canvas = nullptr;

/*----------------------------------------------------------------------------*/

bool SfmlEngine::initialize(int*, char**) {

    canvas = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "sfml",
                                  sf::Style::Fullscreen);

    RunningStatus() = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool& SfmlEngine::RunningStatus() {
    static bool RUNNING_STATUS = false;
    return RUNNING_STATUS;
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::isRunning() {
    return RunningStatus();
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::terminate() {

    RunningStatus() = false;

    delete canvas;
    canvas = nullptr;

    return true;
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::clear() {
    canvas->clear(sf::Color::Black);
}

/*----------------------------------------------------------------------------*/

void SfmlEngine::display() {
    canvas->display();
}

/*============================================================================*/

Vector2<size_t> SfmlEngine::getDisplaySize() {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    return Vector2<size_t>{screen.width, screen.height};
}

/*============================================================================*/
