/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "object_manager.hpp"
#include "ShishGL/core/event/base_event.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public Object {
    public:

        Window() = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual Vector2<double> getRelPos() = 0;

        [[nodiscard]]
        virtual Vector2<double> getAbsPos() = 0;

        void refresh();

        /*--------------------------------------------------------------------*/

        template <typename SomeWindow, typename... Args>
        Object::ID attach(Args&&... args) {

            Object::ID child_id = CREATE<SomeWindow>(std::forward<Args>(args)...);

            subwindows.insert(child_id);
            return child_id;
        }

        bool detach(Object::ID id);

        /*--------------------------------------------------------------------*/

    protected:

        explicit Window(Object::ID id, Object::ID parent);

        using WindowSet = std::unordered_set<Object::ID>;

        WindowSet subwindows;
        Object::ID parent;

        /*--------------------------------------------------------------------*/

        friend class RenderEvent;
        virtual bool onRender() = 0;
    };

    /*========================================================================*/

    class RenderEvent : public Event {
    public:

        explicit RenderEvent() = default;

        bool happen(Object::ID listener) override {
            return GET<Window>(listener).onRender();
        }

        ~RenderEvent() override = default;

    };
}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
