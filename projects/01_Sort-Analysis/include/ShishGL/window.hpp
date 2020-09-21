#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <vector>

#include "essential.hpp"
#include "object.hpp"


namespace ShishGL {

    class Window : public Object {
    public:

        Window() = delete;

        Window(const Vector2<int>& pos, const Vector2<size_t>& size);

        Window(const Window& other);

        Window(Window&& other) noexcept;

        Window& operator=(const Window& other);

        Window& operator=(Window&& other) noexcept;

        virtual ~Window();

        void dump();

        struct WindowInfo {
            int id;
            Vector2<int> pos;
            Vector2<size_t> size;
        };

        void attach(Window* window);

        void refresh() const;

        [[nodiscard]] const WindowInfo& getInfo();

    protected:

        WindowInfo info;

        static const int ID_UNDEFINED = 0;

        std::vector<Window*> subwindows;

        //==========================================================================

        virtual void initLayout() { }

        virtual void onIdle() { }

        virtual void onRender() { }

        virtual void onEntry(int) { }

        virtual void onReshape(int, int) { }

        virtual void onKeyPress(unsigned char, int, int) { }

        virtual void onMouseClick(int, int, int, int) { }

        //==========================================================================

        static void makeActive(Window* window);

        static Window* getCurrentActiveWindow();

    private:

        static constexpr int MAX_ALLOWED_WINDOW_CNT = 200;
        static Window* active_windows[MAX_ALLOWED_WINDOW_CNT + 1];

        static void manageOnIdle();

        static void manageOnRender();

        static void manageOnEntry(int state);

        static void manageOnReshape(int width, int height);

        static void manageOnKeyPress(unsigned char key, int x, int y);

        static void manageOnMouseClick(int button, int state, int x, int y);

    };
}


#endif //WINDOW_HPP
