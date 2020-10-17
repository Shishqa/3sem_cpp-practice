#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP


#include <cstddef>
#include <string_view>

#include "GLUT/graphic_system.hpp"


namespace ShishGL {

    template <typename GraphicSystem>
    class GraphicInterface : public GraphicSystem {
    public:

        using WIN_ID = typename GraphicSystem::WIN_ID;

        virtual ~GraphicInterface() = default;

    private:

        GraphicInterface() = default;
    };

    using GraphicBase = GraphicInterface<GlutSystem>;

}

#endif //GRAPHIC_SYSTEM_HPP
