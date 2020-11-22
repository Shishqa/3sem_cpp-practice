/*============================================================================*/
#include <cstdio>

#include "HoldableWindow.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

HoldableWindow::HoldableWindow(Shape2D* shape)
    : ClickableWindow(shape)
    , n_held(0)
    { }

/*------------------------------------------------------------------------*/

bool HoldableWindow::onMouseButton(MouseButtonEvent& event) {

    if (Mouse::DOWN == event.state()) {
        ++n_held;
        printf("++click\n");
    } else {
        n_held = (n_held ? n_held - 1 : 0);
    }

    return true;
}

/*------------------------------------------------------------------------*/

uint8_t HoldableWindow::numHeld() const {
    return n_held;
}

/*------------------------------------------------------------------------*/

bool HoldableWindow::isHeld() const {
    return (n_held > 0);
}

/*============================================================================*/