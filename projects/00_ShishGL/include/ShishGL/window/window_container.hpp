/*============================================================================*/
#ifndef SHISHGL_WINDOW_CONTAINER_HPP
#define SHISHGL_WINDOW_CONTAINER_HPP
/*============================================================================*/
#include <unordered_set>
#include <type_traits>

#include "window.hpp"
/*============================================================================*/
namespace ShishGL {

    class WindowContainer : public Window {
    public:

        explicit WindowContainer(const Vector2<size_t>& size,
                                 const Vector2<int>& pos = {0, 0});

        WindowContainer() = delete;

        ~WindowContainer() override = default;

    protected:

        using WindowSet = std::unordered_set<Window*>;

        /*--------------------------------------------------------------------*/
        WindowSet subwindows;
        /*--------------------------------------------------------------------*/

        template <typename SomeWindow, typename... Args>
        SomeWindow* attach(Args&&... args) {

            if (!std::is_base_of<Window, SomeWindow>::value) {
                return nullptr;
            }

            auto win_ptr = new SomeWindow(std::forward<Args>(args)...);

            subwindows.insert(win_ptr);
            return win_ptr;
        }

        bool detach(Window* win_ptr);

        /*--------------------------------------------------------------------*/

        bool getEvent(const Event* event) override;

        friend class Application;

    };

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_CONTAINER_HPP
/*============================================================================*/
