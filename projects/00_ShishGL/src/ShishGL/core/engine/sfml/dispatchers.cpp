/*============================================================================*/
#include <cassert>

#include "ShishGL/core/engine/sfml/engine.hpp"
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Event* pollMouseButton(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseButtonPressed ||
           sf_event.type == sf::Event::MouseButtonReleased);

    Mouse::ButtonState state = Mouse::DOWN;
    switch (sf_event.type) {

        case sf::Event::MouseButtonPressed:  state = Mouse::DOWN; break;
        case sf::Event::MouseButtonReleased: state = Mouse::UP;   break;

        default:
            return nullptr;

    }

    Vector2<int> where{
            sf_event.mouseButton.x,
            sf_event.mouseButton.y
    };

    Mouse::Button button = Mouse::LEFT;
    switch (sf_event.mouseButton.button) {

        case sf::Mouse::Left:   button = Mouse::LEFT;   break;
        case sf::Mouse::Right:  button = Mouse::RIGHT;  break;
        case sf::Mouse::Middle: button = Mouse::MIDDLE; break;

        default:
            return nullptr;
    }

    auto event = new MouseButtonEvent(Event::MOUSE_BUTTON, where,
                                      button, state);

    return event;
}

/*----------------------------------------------------------------------------*/

Event* pollMouseScroll(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseWheelScrolled);

    Vector2<int> where{
            sf_event.mouseWheelScroll.x,
            sf_event.mouseWheelScroll.y
    };

    Mouse::ScrollDelta delta = sf_event.mouseWheelScroll.delta;

    auto event = new MouseScrollEvent(Event::MOUSE_SCROLL, where, delta);

    return event;
}

/*----------------------------------------------------------------------------*/

Event* pollMouseMove(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseMoved);

    Vector2<int> where{
            sf_event.mouseMove.x,
            sf_event.mouseMove.y
    };

    auto event = new MouseEvent(Event::MOUSE_MOVE, where);

    return event;
}

/*----------------------------------------------------------------------------*/

Event* pollKeyboard(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::KeyPressed ||
           sf_event.type == sf::Event::KeyReleased);

    Keyboard::Key key = Keyboard::Key::UNKNOWN;

    if (sf_event.key.code <= sf::Keyboard::Num9) {

        key = static_cast<Keyboard::Key>(sf_event.key.code);

    } else {

        key = Keyboard::Key::UNKNOWN;
        /* todo: handle others */

    }

    Keyboard::KeyState state = Keyboard::DOWN;
    if (sf_event.type == sf::Event::KeyPressed) {
        state = Keyboard::DOWN;
    } else {
        state = Keyboard::UP;
    }

    Keyboard::ModifierMask modifiers = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        modifiers |= Keyboard::L_SHIFT_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        modifiers |= Keyboard::R_SHIFT_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        modifiers |= Keyboard::L_CTRL_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
        modifiers |= Keyboard::R_CTRL_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
        modifiers |= Keyboard::L_ALT_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) {
        modifiers |= Keyboard::R_ALT_MOD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)) {
        modifiers |= Keyboard::META_MOD;
    }

    auto event = new KeyboardEvent(Event::KBD_BUTTON, key, state, modifiers);

    return event;
}

/*----------------------------------------------------------------------------*/

Event* SfmlEngine::pollEvent() {

    sf::Event sfml_event = {};

    bool status = canvas->pollEvent(sfml_event);
    if (!status) {
        return nullptr;
    }

    switch (sfml_event.type) {

        case sf::Event::Closed:
            is_running = false;
            break;

        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
            return pollMouseButton(sfml_event);

        case sf::Event::MouseMoved:
            return pollMouseMove(sfml_event);

        case sf::Event::MouseWheelScrolled:
            return pollMouseScroll(sfml_event);

        case sf::Event::KeyPressed:
        case sf::Event::KeyReleased:
            return pollKeyboard(sfml_event);

        default: break;
    }

    return nullptr;
}

/*============================================================================*/