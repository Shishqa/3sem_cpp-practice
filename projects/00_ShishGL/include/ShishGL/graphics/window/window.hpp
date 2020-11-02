/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "ShishGL/core/object/renderable_object.hpp"
#include "ShishGL/core/event/event.hpp"
#include "ShishGL/core/geometry/vector2.hpp"
#include "ShishGL/graphics/shapes/shape2d.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public RenderableObject {
    public:

        Window() = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        bool onRender() override;

        [[nodiscard]]
        Vector2<double> getAbsPos() const override;

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        /*--------------------------------------------------------------------*/

        bool onMouseMove(const MouseEvent* event) override;

        virtual void onMouseEnter(const MouseEvent*) { /* nothing */ }

        virtual void onMouseLeave(const MouseEvent*) { /* nothing */ }

    protected:

        bool is_mouse_inside;
        Shape2D* shape;

        template <typename SomeShape, typename... Args>
        explicit Window(RenderableObject* parent, Args&&... args)
                : RenderableObject() {
            shape = new SomeShape(std::forward<Args>(args)...);
            is_mouse_inside = shape->contains(Engine::getMousePos());
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
