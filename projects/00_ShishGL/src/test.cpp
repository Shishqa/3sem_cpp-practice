/*============================================================================*/
#include "ShishGL/graphics/shapes/shape2d.hpp"
#include "ShishGL.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "ShishGL/user_interface/viewport/viewport.hpp"
#include "ShishGL/user_interface/text_buffer/text_buffer.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CoreApplication::create<RectWindow>(
            nullptr,
            WHITE,
            Vector2<double>{50, 50},
            Vector2<double>{100, 100}
            );

    CoreApplication::create<RectButton>(
            nullptr,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{50, 50},
            Vector2<double>{200, 100}
    );

    CoreApplication::create<RectFloat>(
            nullptr,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{50, 50},
            Vector2<double>{300, 100}
    );

    CoreApplication::create<RectSlider>(
            nullptr,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{200, 0},
            Vector2<double>{50, 50},
            Vector2<double>{400, 100}
    );

    CoreApplication::create<Scrollbar>(
            nullptr,
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<double>{50, 700},
            Vector2<double>{300, 300}
            );

    CoreApplication::create<TextBuffer>(
            nullptr,
            std::string_view("Makefile"),
            Vector2<double>{700, 300},
            Vector2<double>{500, 500}
            );

    return CoreApplication::run();
}

/*============================================================================*/
