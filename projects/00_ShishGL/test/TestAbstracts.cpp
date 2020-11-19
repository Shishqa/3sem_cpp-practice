/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "ColorCollection.hpp"
//#include "WindowTypes.hpp"
#include "CursorLocator.hpp"
#include "ColorFill.hpp"
#include "TextureFill.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

/*
class NestedTester : public Window {
public:

    NestedTester(Object::ID id, Object::ID shape, Object::ID parent = LayoutManager::ROOT)
                 : Window(id, shape, parent)
                 { }

    void initLayout() override {

        attach<CursorLocator, Rectangle>(
                YELLOW,
                Vector2<double>{40, 40}
        );

    }

    ~NestedTester() override = default;

};

class NestedTesterParent : public Window {
public:

    NestedTesterParent(Object::ID id, Object::ID shape,
                       Object::ID parent = LayoutManager::ROOT)
            : Window(id, shape, parent)
    { }

    void initLayout() override {

        attach<CursorLocator, Circle>(
                BLUE, 20
        );

        attach<NestedTester, Circle>(
                DARK_VIOLET, 100,
                Vector2<double>{100, 100}
        );

    }

    ~NestedTesterParent() override = default;

};
*/

/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    auto win = WindowManager::create<Window, CircleShape>(
            300,
            Vector2<double>{200, 200}
            );

    win->applyStyle<TextureFill>("textures/PaperTexture.jpg");

    auto loc = WindowManager::create<CursorLocator, RectangleShape>(
            Vector2<double>{50, 50}
            );

    loc->applyStyle<TextureFill>("textures/Transparent.png");

    WindowManager::attach(win, loc);

    WindowManager::dump("LayoutDump.dot");

    return CoreApplication::run();

}

/*============================================================================*/
