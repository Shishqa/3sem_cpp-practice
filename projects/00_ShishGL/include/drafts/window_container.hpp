/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
#define SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
/*============================================================================*/
#include <unordered_set>
#include <type_traits>

#include "../ShishGL/core/window.hpp"
/*============================================================================*/
namespace ShishGL {

    class WindowContainer : public Window {
    protected:

        using WindowSet = std::unordered_set<Window*>;

        WindowSet subwindows;

    public:

        explicit WindowContainer(Window* parent = nullptr);

        WindowContainer() = delete;

        ~WindowContainer() override;

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

        Window* detach(Window* win_ptr);
        /*--------------------------------------------------------------------*/

    protected:

        bool getEvent(const Event* event) override;

        friend class EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_CONTAINER_HPP
/*============================================================================*/
