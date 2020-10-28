/*============================================================================*/
#include "ShishGL.hpp"
#include "test/dummy_button.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CoreApplication::create<DummyButton<Rectangle>>(
            nullptr,
            Vector2<int>{100, 100},
            Vector2<size_t>{300, 200}
            );

    return CoreApplication::run();
}

/*============================================================================*/
