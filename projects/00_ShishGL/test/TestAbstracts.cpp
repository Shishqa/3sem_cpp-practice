/*============================================================================*/
#include "CoreApplication.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "ColorCollection.hpp"
#include "WindowTypes.hpp"
//#include "CursorLocator.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

class NestedTester : public Window {
public:

    NestedTester(Object::ID id, Object::ID shape, Object::ID parent = LayoutManager::ROOT)
                 : Window(id, shape, parent)
                 { }

    void initLayout() override {

        attach<Window, Rectangle>(
                GREEN,
                Vector2<double>{50, 50},
                Vector2<double>{-25, -25}
        );

    }

    ~NestedTester() override = default;

};

/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    WindowManager::create<NestedTester, Rectangle>(
            WHITE_SMOKE,
            Vector2<double>{100, 100},
            Vector2<double>{100, 100}
            );

    LayoutManager::dump("LayoutDump.dot");

    /*
    CREATE<DraggableWindow<Rectangle>>(
            ObjectManager::ID_UNDEFINED,
            WHITE_SMOKE,
            Vector2<double>{100, 100},
            Vector2<double>{100, 250}
            );

    CREATE<SlidableWindow<Rectangle>>(
            ObjectManager::ID_UNDEFINED,
            Segment2<double>{{100, 400}, {100, 700}},
            WHITE_SMOKE,
            Vector2<double>{100, 100},
            Vector2<double>{100, 400}
            );

    CREATE<Window<Circle>>(
            ObjectManager::ID_UNDEFINED,
            WHEAT, 50,
            Vector2<double>{350, 100}
    );

    CREATE<DraggableWindow<Circle>>(
            ObjectManager::ID_UNDEFINED,
            WHEAT, 50,
            Vector2<double>{350, 250}
    );

    CREATE<SlidableWindow<Circle>>(
            ObjectManager::ID_UNDEFINED,
            Segment2<double>{{350, 400}, {350, 700}},
            WHEAT, 50,
            Vector2<double>{350, 400}
    );

    CREATE<CursorLocator>(
            ObjectManager::ID_UNDEFINED
    );

     */

    return CoreApplication::run();

}

/*============================================================================*/
