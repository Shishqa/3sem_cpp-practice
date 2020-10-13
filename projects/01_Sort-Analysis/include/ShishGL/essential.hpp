#ifndef ESSENTIAL_HPP
#define ESSENTIAL_HPP


#include "vector2.hpp"
#include "graphic_interface.hpp"
#include "GLUT/graphic_system.hpp"


namespace ShishGL {

    using GI = GraphicInterface<GlutSystem>;

    int init(int* argc_ptr, char** argv);

    int enterMainLoop();

    void terminate();

}


#endif //ESSENTIAL_HPP
