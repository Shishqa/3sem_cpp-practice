#include <cstdio>


#include "graphic_system.hpp"
#include "sfml_impl.hpp"
#include "txlib_impl.hpp"


int main() {
    
    GraphicSystem<SfmlImpl>::draw_rect();

    return 0;
}
