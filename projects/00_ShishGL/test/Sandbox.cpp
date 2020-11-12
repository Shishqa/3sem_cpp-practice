/*============================================================================*/
#include "CoreApplication.hpp"
#include "Rectangle.hpp"
#include "ColorCollection.hpp"
#include "WindowTypes.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

class ClickTester : public ClickableWindow<Rectangle> {
public:

    ClickTester(Object::ID id, Object::ID parent,
                const Vector2<double>& size,
                const Vector2<double>& pos)
            : ClickableWindow<Rectangle>(id, parent, WHITE, size, pos) {}

protected:

    bool onMouseButton(MouseButtonEvent& event) override {

        if (Mouse::DOWN == event.state()) {
            printf("I AM CLICKED DOWN!\n");
            Window<Rectangle>::getShape().setColor(RED);
        } else {
            printf("I AM RELEASED\n");
            Window<Rectangle>::getShape().setColor(WHITE);
        }

        return true;
    }

};

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CREATE<Rectangle>(
            WHITE_SMOKE,
            Vector2<double>{1000, 100},
            Vector2<double>{100, 500}
            );

    CREATE<DraggableWindow<Rectangle>>(
            ObjectManager::ID_UNDEFINED,
            WHITE_SMOKE,
            Vector2<double>{1000, 200},
            Vector2<double>{300, 200}
            );

    CREATE<SlidableWindow<Rectangle>>(
            ObjectManager::ID_UNDEFINED,
            Segment2<double>{{0, 0}, {100, 0}},
            WHITE_SMOKE,
            Vector2<double>{100, 100}
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
