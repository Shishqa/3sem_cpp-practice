/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "ShishGL/core/object.hpp"
#include "ShishGL/core/event/event.hpp"
#include "ShishGL/core/geometry/vector2.hpp"
#include "ShishGL/core/geometry/shape2d.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public RenderableObject {
    public:

        Window() = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        Vector2<double> getRelPos() const;

        [[nodiscard]]
        const Vector2<double>& getAbsPos() const;

        void refresh();

        /*--------------------------------------------------------------------*/
        template <typename SomeWindow, typename... Args>
        SomeWindow* attach(Args&&... args) {

            /* TODO: sfinae! */
            if (!std::is_base_of<Window, SomeWindow>::value) {
                return nullptr;
            }

            auto win_ptr = new SomeWindow(this, std::forward<Args>(args)...);

            subwindows.insert(win_ptr);
            return win_ptr;
        }

        Window* detach(Window* win_ptr);
        /*--------------------------------------------------------------------*/

        bool onRender() override;

        bool onMouseMove(const MouseEvent* event) override;

        virtual void onMouseEnter(const MouseEvent*) { /* nothing */ }

        virtual void onMouseLeave(const MouseEvent*) { /* nothing */ }

    protected:

        using WindowSet = std::unordered_set<Window*>;

        Window* parent;
        WindowSet subwindows;

        bool is_mouse_inside;
        Shape2D* shape;

        template <typename SomeShape, typename... Args>
        explicit Window(Window* parent, Args&&... args)
                : RenderableObject()
                , parent(parent) {
            shape = new SomeShape(std::forward<Args>(args)...);
            is_mouse_inside = shape->contains(Engine::getMousePos());
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
