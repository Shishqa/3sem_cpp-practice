/*============================================================================*/
#include "ShishGL.hpp"
#include "ShishGL/widgets/scrollbar/scrollbar.hpp"
#include "test/dummy_button.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CoreApplication::create<RectFloat>(
            nullptr,
            DEFAULT_BUTTON_COLORS,
            Vector2<int>{500, 500},
            Vector2<size_t>{50, 50}
    );

    CoreApplication::create<Scrollbar>(
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<int>{100, 100},
            Vector2<size_t>{50, 600}
            );

    CoreApplication::create<DummyButton<Rectangle>>(
            nullptr,
            Vector2<int>{1000, 500},
            Vector2<size_t>{50, 50}
            );

    return CoreApplication::run();
}

/*============================================================================*/
