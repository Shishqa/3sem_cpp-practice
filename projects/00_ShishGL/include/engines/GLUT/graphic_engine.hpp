/*============================================================================*/
#ifndef GLUT_GRAPHIC_ENGINE_HPP
#define GLUT_GRAPHIC_ENGINE_HPP
/*============================================================================*/

#include <cstddef>
#include <string_view>
#include <queue>

#include "../../vector2.hpp"

/*============================================================================*/

namespace ShishGL {

    class GlutGraphicEngine {
    public:

        virtual ~GlutGraphicEngine() = default;

    private:

        GlutGraphicEngine() = default;
    };

}

/*============================================================================*/
#endif //GLUT_GRAPHIC_ENGINE_HPP
/*============================================================================*/
