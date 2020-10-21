/*============================================================================*/
#ifndef SHISHGL_WINDOW_CONTAINER_HPP
#define SHISHGL_WINDOW_CONTAINER_HPP
/*============================================================================*/

#include <unordered_set>
#include <string_view>

#include "window.hpp"

/*============================================================================*/

namespace ShishGL {

    class WindowContainer : public Window {
    public:

        WindowContainer() = delete;

        explicit WindowContainer(const Vector2<size_t>& size,
                                 const Vector2<int>& pos = {0, 0},
                                 const std::string_view& win_title = "");

        ~WindowContainer() override = default;

    protected:

        std::unordered_set<Window*> subwindows;

        template <typename T, typename... Args>
        T* attach(Args&&... args) {
            T* win_ptr = new T(std::forward<Args>(args)...);
            subwindows.insert(win_ptr);
            return win_ptr;
        }

    private:

        /* event handling for subwindows */

    };

}

/*============================================================================*/
#endif //SHISHGL_WINDOW_CONTAINER_HPP
/*============================================================================*/
