/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>
#include <unordered_set>

#include "object.hpp"
#include "event.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public Object {
    protected:

        using WindowSet = std::unordered_set<Window*>;

        WindowSet subwindows;

        Window* parent;

    public:

        explicit Window(Window* parent = nullptr);

        Window() = delete;

        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual Vector2<int> getRelPos() = 0;

        [[nodiscard]]
        virtual Vector2<int> getAbsPos() = 0;

        void refresh();

        /*--------------------------------------------------------------------*/

    protected:

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

        bool getEvent(const Event* event) override;

        virtual void onRender() = 0;
    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
