/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
#define SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
/*============================================================================*/
#include <unordered_set>
#include <type_traits>

#include "window.hpp"
/*============================================================================*/
namespace ShishGL {

    class alignas(8) WindowContainer : public Window {
    protected:

        using WindowSet = std::unordered_set<Window*>;

        WindowSet subwindows;

    public:

        explicit WindowContainer(Window* parent,
                                 const Vector2<int>& pos = {0, 0});

        WindowContainer() = delete;

        ~WindowContainer() override = default;

        /*--------------------------------------------------------------------*/
        template <typename SomeWindow, typename... Args>
        SomeWindow* attach(Args&&... args) {

            /* TODO: sfinae! */
            if (!std::is_base_of<Window, SomeWindow>::value) {
                return nullptr;
            }

            auto win_ptr = new SomeWindow(std::forward<Args>(args)...);

            subwindows.insert(win_ptr);
            return win_ptr;
        }

        bool detach(Window* win_ptr);
        /*--------------------------------------------------------------------*/

    protected:

        bool getEvent(const Event* event) override;

        friend class EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
/*============================================================================*/
