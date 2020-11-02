/*============================================================================*/
#include "ShishGL/graphics/window/button.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool Button::onMouseClick(const MouseButtonEvent* event) {

    if(event->button() == Mouse::LEFT) {
        if (event->state() == Mouse::DOWN) {

            is_pressed = true;
            reactOnButton(event);

ShapedWindow<SomeShape>::color = colorscheme.click;

} else if (is_pressed) {

is_pressed = false;
reactOnButton(event);

if (ShapedWindow<SomeShape>::contains(event->where())) {
ShapedWindow<SomeShape>::color = colorscheme.hover;
} else {
ShapedWindow<SomeShape>::color = colorscheme.normal;
}
}
}
return true;
}

bool onMouseEntered(const MouseEvent*) override {
if (!is_pressed) {
ShapedWindow<SomeShape>::color = colorscheme.hover;
}
return true;
}

bool onMouseLeft(const MouseEvent*) override {
if (!is_pressed) {
ShapedWindow<SomeShape>::color = colorscheme.normal;
}
return true;
}

bool onTimer(const TimerEvent*) override;

/*============================================================================*/
