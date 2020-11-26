/*============================================================================*/
#include "ColorFill.hpp"
#include "ColorCollection.hpp"
#include "UIWindow.hpp"
#include "Draggable.hpp"
#include "YAGE.hpp"
#include "Canvas.hpp"
/*============================================================================*/
using namespace YAGE;
using namespace ShishGL;
/*============================================================================*/

void YAGE::create() {

    constexpr double WIN_WIDTH  = 1600;
    constexpr double WIN_HEIGHT = 1000;

    auto holder = WindowManager::create<UIWindow>(
            Viewport{
                    {100, 20},
                    {WIN_WIDTH + 20, WIN_HEIGHT + 50}
            }
            );
    holder->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::PALE_VIOLET_RED}
            );

    auto main_win = holder->attach<UIWindow>(
            Viewport{
                    {10, 40},
                    {WIN_WIDTH, WIN_HEIGHT}
            }
    );

    auto canvas_frame = main_win->attach<UIWindow>(
            Viewport{
                    {200, 50},
                    {WIN_WIDTH - 200, WIN_HEIGHT - 50}
            }
            );
    canvas_frame->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{10, 10, 10, 255}}
            );

    canvas_frame->attach<Canvas>(
            Viewport{
                    {50, 50},
                    {900, 600}
            }
            );

    auto tools = main_win->attach<UIWindow>(
            Viewport{
                    {0, 50},
                    {200, WIN_HEIGHT - 50}
            }
            );
    tools->applyStyle<UIWindow::NORMAL>(
            ColorFill(COLOR::PAPAYA_WHIP)
            );

    auto menu = main_win->attach<UIWindow>(
            Viewport{
                    {0, 0},
                    {WIN_WIDTH, 50}
            }
            );
    menu->applyStyle<UIWindow::NORMAL>(
            ColorFill(Color{32, 32, 32, 255})
            );

     /*
    auto win = WindowManager::create<Canvas>(
            Viewport{{0, 0}, {400, 400}}
            );
    win->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::RED}
            );
    */

    WindowManager::putRoot(holder);

}