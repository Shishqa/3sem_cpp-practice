/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "ColorCollection.hpp"
//#include "WindowTypes.hpp"
//#include "CursorLocator.hpp"
#include "ColorFill.hpp"
#include "TextureFill.hpp"
#include "Bordered.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    auto win = WindowManager::create<UIWindow<CircleShape>>(
            Viewport{
                Vector2<double>{0, 0},
                Vector2<double>{400, 400}
            }
            );
    win->applyStyle<Bordered>(5, RED);
    win->applyStyle<TextureFill>("textures/PaperTexture.jpg");

    auto button = WindowManager::create<UIWindow<RectangleShape>>(
            Viewport{
                Vector2<double>{200, 200},
                Vector2<double>{400, 400}
            }
            );
    button->applyStyle<Bordered>(10, GREEN);
    button->applyStyle<ColorFill>(BROWN);

    WindowManager::putRoot(button);
    WindowManager::attach(button, win);

    WindowManager::dump("LayoutDump.dot");

    return CoreApplication::run();

}

/*============================================================================*/
