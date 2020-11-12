/*============================================================================*/
#ifndef SHISHGL_GRAPHIC_OBJECT_HPP
#define SHISHGL_GRAPHIC_OBJECT_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "Object.hpp"
#include "Event.hpp"
/*============================================================================*/
namespace ShishGL {

    class GraphicObject : public Object {
    public:

        explicit GraphicObject(Object::ID id);

    protected:

        friend class RenderEvent;
        virtual bool onRender() = 0;
    };

    /*========================================================================*/

    class RenderEvent : public Event {
    public:

        explicit RenderEvent() = default;

        bool happen(Object::ID listener) override;

        ~RenderEvent() override = default;

    };
}
/*============================================================================*/
#endif //SHISHGL_GRAPHIC_OBJECT_HPP
/*============================================================================*/
