#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <vector>
#include <unordered_map>

#include "essential.hpp"
#include "object.hpp"


namespace ShishGL {

    class WindowManager;

    class Window : public Object {
    public:

        Window() = delete;

        Window(const Vector2<int>& pos, const Vector2<size_t>& size);

//        Window(const Window& other);
//
//        Window(Window&& other) noexcept;
//
//        Window& operator=(const Window& other);
//
//        Window& operator=(Window&& other) noexcept;

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

        friend WindowManager;

        WindowInfo info;

        std::vector<Window*> subwindows;

        //==========================================================================

        virtual void initLayout() = 0;

        virtual void onIdle() = 0;

        virtual void onRender() = 0;

        virtual void onEntry(int) = 0;

        virtual void onReshape(int, int) = 0;

        virtual void onKeyPress(unsigned char, int, int) = 0;

        virtual void onMouseClick(int, int, int, int) = 0;
    };


    class WindowManager {
    public:

        static constexpr int WIN_ID_UNDEFINED = 0;

        static void makeActive(Window* window);

        static Window* getCurrentActiveWindow();

    private:

        using WindowMap = std::unordered_map<int, Window*>;

        static WindowMap& ActiveWindows();

        static void manageOnIdle();

        static void manageOnRender();

        static void manageOnEntry(int state);

        static void manageOnReshape(int width, int height);

        static void manageOnKeyPress(unsigned char key, int x, int y);

        static void manageOnMouseClick(int button, int state, int x, int y);
    };
}


#endif //WINDOW_HPP
