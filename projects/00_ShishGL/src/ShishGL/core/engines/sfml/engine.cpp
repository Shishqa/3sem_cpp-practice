/*============================================================================*/
#include "ShishGL/core/engines/sfml/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

sf::RenderWindow* SfmlEngine::canvas = nullptr;

/*----------------------------------------------------------------------------*/

bool SfmlEngine::initialize(int*, char**) {

    canvas = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "sfml",
                                  sf::Style::Fullscreen);

    return true;
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::terminate() {

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

/*----------------------------------------------------------------------------*/


void pollMouse(sf::Event& sf_event, Event& event) {

    if ()

}


bool SfmlEngine::pollEvent(Event& event) {

    sf::Event sfml_event = {};

    bool status = canvas->pollEvent(sfml_event);
    if (!status) {
        return false;
    }

    switch (sfml_event.type) {

        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
        case sf::Event::MouseEntered:
        case sf::Event::MouseLeft:
        case sf::Event::MouseMoved:
        case sf::E:
            break;

    }


    if (sf::Event::Closed == sfml_event.type) {
        event.type = Event::TERMINATE;
    } else {
        status = false;
    }

}

/*============================================================================*/

Vector2<size_t> SfmlEngine::getDisplaySize() {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    return Vector2<size_t>{screen.width, screen.height};
}

/*============================================================================*/
