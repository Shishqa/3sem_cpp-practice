/*============================================================================*/
#ifndef SHISHGL_RENDERABLE_HPP
#define SHISHGL_RENDERABLE_HPP
/*============================================================================*/
#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class Renderable : public Object {
    public:

        explicit Renderable(Object::ID id)
            : Object(id)
            { }

        ~Renderable() override = default;

    protected:

        friend class RenderSystem;

        virtual bool onRender() = 0;
    };

}
/*============================================================================*/
#endif //SHISHGL_RENDERABLE_HPP
/*============================================================================*/
