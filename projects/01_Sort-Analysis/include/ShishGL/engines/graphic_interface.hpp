/*============================================================================*/
#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP
/*============================================================================*/

#include <cstddef>
#include <string_view>

#include "GLUT/graphic_engine.hpp"
#include "GLUT/window_engine.hpp"

/*============================================================================*/

namespace ShishGL {

    template <typename GraphicEngine, typename WindowEngine>
    class GraphicInterface : public GraphicEngine, public WindowEngine {
    public:

        using WIN_ID = typename WindowEngine::WIN_ID;

        virtual ~GraphicInterface() = default;

    private:

        GraphicInterface() = default;
    };

    using Engine = GraphicInterface<GlutGraphicEngine, GlutWindowEngine>;

}

/*============================================================================*/
#endif //GRAPHIC_SYSTEM_HPP
/*============================================================================*/
