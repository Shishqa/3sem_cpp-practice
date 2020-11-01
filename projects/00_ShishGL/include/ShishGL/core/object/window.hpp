/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "object.hpp"
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

    protected:

        explicit Window(Window* parent = nullptr);

        using WindowSet = std::unordered_set<Window*>;

        WindowSet subwindows;

        Window* parent;

        /*--------------------------------------------------------------------*/

        bool getEvent(const Event* event) override;

        virtual void onRender() = 0;
    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
