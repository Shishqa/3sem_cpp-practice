/*============================================================================*/
#include "ShishGL.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
#include "test/dummy_button.hpp"
#include "ShishGL/user_interface/viewport/viewport.hpp"
#include "ShishGL/user_interface/text_buffer/text_buffer.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CoreApplication::create<RectFloat>(
            nullptr,
            DEFAULT_BUTTON_COLORS,
            Vector2<int>{100, 100},
            Vector2<size_t>{50, 50}
    );

    CoreApplication::create<Scrollbar>(
            nullptr,
            nullptr,
            DEFAULT_SCROLLBAR_COLORS,
            Vector2<int>{300, 300},
            Vector2<size_t>{50, 700}
            );

    CoreApplication::create<TextBuffer>(
            nullptr,
            std::string_view("Makefile"),
            Vector2<int>{500, 500},
            Vector2<size_t>{700, 300}
            );

    return CoreApplication::run();

    return 0;
}

/*============================================================================*/
