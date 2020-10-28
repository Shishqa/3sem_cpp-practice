/*============================================================================*/
#include "ShishGL.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CoreApplication::create<RectWindow>(
            Vector2<int>{100, 100},
            Vector2<size_t>{500, 700},
            BLUE_VIOLET
            );

    return CoreApplication::run();
}

/*============================================================================*/
