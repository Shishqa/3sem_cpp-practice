/*============================================================================*/
#ifndef SHISHGL_GRAPHIC_OBJECT_HPP
#define SHISHGL_GRAPHIC_OBJECT_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class GraphicObject : public Object {
    public:

        explicit GraphicObject(Object::ID id);

    protected:

        friend class RenderSystem;

        virtual bool onRender() = 0;
    };

}
/*============================================================================*/
#endif //SHISHGL_GRAPHIC_OBJECT_HPP
/*============================================================================*/
