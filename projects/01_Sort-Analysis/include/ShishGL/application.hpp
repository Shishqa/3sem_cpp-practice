/*============================================================================*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/*============================================================================*/

#include <cstdint>

#include "window_manager.hpp"

/*============================================================================*/

namespace ShishGL {

    class Application {
    private:

        Application() = default;

    public:

        virtual ~Application() = default;

        static void init(int* argc_ptr, char** argv);

        template <typename T, typename... Args>
        static T* display(Args&&... args) {
            T* win_p = new T(std::forward<Args>(args)...);
            RootWindows().insert(win_p);
            win_p->display();
            return win_p;
        }

        static uint8_t run();

    protected:

        using WindowSet = std::unordered_set<Window*>;

        static WindowSet& RootWindows();
    };

}

/*============================================================================*/

#endif //APPLICATION_HPP

/*============================================================================*/
