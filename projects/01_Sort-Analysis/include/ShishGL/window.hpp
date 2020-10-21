#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <vector>
#include <unordered_map>

//#include "essential.hpp"
#include "object.hpp"


namespace ShishGL {

    class WindowManager;

    class Window {
    public:

        static constexpr int ID_UNDEFINED = 0;

        struct WindowInfo {
            const std::string_view name;
            typename GraphicBase::WIN_ID id;
            Vector2<int> pos;
            Vector2<size_t> size;
        };

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        Window() = delete;

        explicit Window(const Vector2<size_t>& size,
                        const Vector2<int>& pos = {0, 0},
                        const std::string_view& win_title = "");

        virtual ~Window();

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        void display();

        void close();

//        void refresh() const;

//        void dump();

        [[nodiscard]] const WindowInfo& getInfo();

    protected:

        friend WindowManager;

        WindowInfo info;

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        virtual void onRender() { /* nothing */ }

        virtual void onReshape(int, int) { /* nothing */ }

        virtual void onIdle() { /* nothing to do on idle */ }

        virtual void onMouse(int) { /* nothing */ }

        virtual void onKey(unsigned char, int, int) { /* nothing */ }
    };

}


#endif //WINDOW_HPP
