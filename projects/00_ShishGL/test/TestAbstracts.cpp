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

int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    CREATE<CursorLocator>(
            ObjectManager::ID_UNDEFINED
    );

    CREATE<Window<Rectangle>>(
            ObjectManager::ID_UNDEFINED,
            WHITE_SMOKE,
            Vector2<double>{100, 100},
            Vector2<double>{100, 100}
            );

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


    return CoreApplication::run();

}

/*============================================================================*/
