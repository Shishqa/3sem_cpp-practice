/*============================================================================*/
#include <cstdio>

#include "ClickableWindow.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ClickableWindow::ClickableWindow(Shape2D* shape)
        : Window(shape)
        { }

/*----------------------------------------------------------------------------*/

bool ClickableWindow::filterEvent(Event& event) const {
    try {

        auto mouse_button = dynamic_cast<const MouseButtonEvent&>(event);

        if (mouse_button.state() != Mouse::DOWN) {
            return true;
        }

        if (!contains(mouse_button.where())) {

            printf("clicked at (%lg %lg) i am at {%lg %lg}\n",
                   mouse_button.where().x, mouse_button.where().y,
                   getPos().x, getPos().y);

            return false;
        }
        return true;

    } catch (...) {

        return true;

    }
}

/*============================================================================*/
