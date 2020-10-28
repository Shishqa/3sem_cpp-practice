/*============================================================================*/
#include <cassert>

#include "ShishGL/core/engines/sfml/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void pollMouseClick(Event& event, const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseButtonPressed ||
           sf_event.type == sf::Event::MouseButtonReleased);

    event.type = Event::MOUSE_CLICK;

    event.mouse_button.where = Vector2<int>{
            sf_event.mouseButton.x, sf_event.mouseButton.y
    };

    if (sf_event.type == sf::Event::MouseButtonPressed) {
        event.mouse_button.state = Mouse::DOWN;
    } else {
        event.mouse_button.state = Mouse::UP;
    }

    switch (sf_event.mouseButton.button) {

        case sf::Mouse::Left:
            event.mouse_button.button = Mouse::LEFT;
            break;

        case sf::Mouse::Right:
            event.mouse_button.button = Mouse::RIGHT;
            break;

        case sf::Mouse::Middle:
            event.mouse_button.button = Mouse::MIDDLE;
            break;

        default:
            event.type = Event::NONE;
    }

}

/*----------------------------------------------------------------------------*/

void pollMouseScroll(Event& event, const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseWheelScrolled);

    event.type = Event::MOUSE_SCROLL;

    event.mouse_wheel.where = Vector2<int> {
            sf_event.mouseWheel.x, sf_event.mouseWheel.y
    };

    if (sf_event.mouseWheel.delta >= 0) {
        event.mouse_wheel.wheel = Mouse::SCROLL_UP;
    } else {
        event.mouse_wheel.wheel = Mouse::SCROLL_DOWN;
    }
}

/*----------------------------------------------------------------------------*/

void pollMouseMove(Event& event, const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseMoved);

    event.type = Event::MOUSE_MOVE;

    event.mouse_cursor.where = Vector2<int> {
            sf_event.mouseMove.x, sf_event.mouseMove.y
    };

    event.mouse_cursor.state = Mouse::MOVED;
}

/*----------------------------------------------------------------------------*/

bool SfmlEngine::pollEvent(Event& event) {

    sf::Event sfml_event = {};

    bool status = canvas->pollEvent(sfml_event);
    if (!status) {
        return false;
    }

    switch (sfml_event.type) {

        case sf::Event::Closed:
            RunningStatus() = false;
            break;

        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
            pollMouseClick(event, sfml_event);
            break;

        case sf::Event::MouseMoved:
            pollMouseMove(event, sfml_event);
            break;

        case sf::Event::MouseWheelScrolled:
            pollMouseScroll(event, sfml_event);
            break;

        default:
            event.type = Event::NONE;

    }

    return true;
}

/*============================================================================*/