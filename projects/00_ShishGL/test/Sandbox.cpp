/*============================================================================*/
#include "CoreApplication.hpp"
#include "Rectangle.hpp"
#include "ColorCollection.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CREATE<Rectangle>(
            WHITE_SMOKE,
            Vector2<double>{1000, 100},
            Vector2<double>{100, 500}
            );

    /*
    CREATE<RectWindow>(
            0,
            WHITE,
            Vector2<double>{50, 50},
            Vector2<double>{100, 100}
            );

    CREATE<RectButton>(
            0,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{50, 50},
            Vector2<double>{200, 100}
    );

    CREATE<RectFloat>(
            0,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{50, 50},
            Vector2<double>{300, 100}
    );

    CREATE<RectSlider>(
            0,
            DEFAULT_BUTTON_COLORS,
            Vector2<double>{200, 0},
            Vector2<double>{50, 50},
            Vector2<double>{400, 100}
    );



    CoreApplication::create<Scrollbar>(
            0,
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<double>{50, 700},
            Vector2<double>{300, 300}
            );



    CoreApplication::create<TextBuffer>(
            0,
            std::string_view("Makefile"),
            Vector2<double>{700, 300},
            Vector2<double>{500, 500}
            );


     */

    return CoreApplication::run();

}

/*============================================================================*/
