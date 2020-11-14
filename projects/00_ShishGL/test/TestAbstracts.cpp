/*============================================================================*/
#include "CoreApplication.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "ColorCollection.hpp"
#include "WindowTypes.hpp"
#include "CursorLocator.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

class NestedTester : public Window {
public:

    NestedTester(Object::ID id, Object::ID shape, Object::ID parent = LayoutManager::ROOT)
                 : Window(id, shape, parent)
                 { }

    void initLayout() override {

        setViewportUse(true);

        attach<Window, Rectangle>(
                GREEN,
                Vector2<double>{50, 50},
                Vector2<double>{-25, -25}
        );

        attach<CursorLocator, Rectangle>(
                YELLOW,
                Vector2<double>{30, 30}
        );

    }

    ~NestedTester() override = default;

};

class NestedTester1 : public Window {
public:

    NestedTester1(Object::ID id, Object::ID shape, Object::ID parent = LayoutManager::ROOT)
            : Window(id, shape, parent)
    { }

    void initLayout() override {

        setViewportUse(true);

        attach<Window, Rectangle>(
                DARK_VIOLET,
                Vector2<double>{50, 50},
                Vector2<double>{-25, -25}
        );

        attach<CursorLocator, Rectangle>(
                BLUE,
                Vector2<double>{30, 30}
        );

    }

    ~NestedTester1() override = default;

};

/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    WindowManager::create<NestedTester, Rectangle>(
            DARK_SEA_GREEN,
            Vector2<double>{100, 100},
            Vector2<double>{600, 600}
            );

    WindowManager::create<NestedTester, Rectangle>(
            GRAY,
            Vector2<double>{100, 100},
            Vector2<double>{700, 700}
    );

    WindowManager::create<NestedTester1, Rectangle>(
            PALE_VIOLET_RED,
            Vector2<double>{100, 100},
            Vector2<double>{700, 600}
    );

    WindowManager::create<NestedTester1, Rectangle>(
            PALE_VIOLET_RED,
            Vector2<double>{100, 100},
            Vector2<double>{600, 700}
    );

    LayoutManager::dump("LayoutDump.dot");

    return CoreApplication::run();

}

/*============================================================================*/
