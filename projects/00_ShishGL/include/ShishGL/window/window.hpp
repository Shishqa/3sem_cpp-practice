/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <cstddef>

#include "ShishGL/geometry/vector2.hpp"
#include "ShishGL/object.hpp"
/*============================================================================*/
namespace ShishGL {

    /*------------------------------------------------------------------------*/
    class WindowManager;
    /*------------------------------------------------------------------------*/

    class Window : public Object {
    protected:

        struct WindowInfo {
            Vector2<int>    pos;
            Vector2<size_t> size;
        };
        WindowInfo info;

    public:

        explicit Window(const Vector2<size_t>& size,
                        const Vector2<int>& pos = {0, 0});

        Window() = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const WindowInfo& getInfo() const;

        void display() const;
        void close() const;

        void refresh();

    protected:

        bool getEvent(const Event* event) override;

        /* Event handlers */
        /*--------------------------------------------------------------------*/
        virtual void onRender() { /* nothing */ }

        virtual void onIdle() { /* nothing */ }

        virtual void onMouse(int) { /* nothing */ }

        virtual void onKey(unsigned char, int, int) { /* nothing */ }
        /*--------------------------------------------------------------------*/

        friend WindowManager;
    };

}
/*============================================================================*/
#endif //WINDOW_HPP
/*============================================================================*/
