/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include "SubscriptionManager.hpp"
#include "PlatformListener.hpp"
#include "MouseEvent.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public PlatformListener {
    public:

        struct Viewport {
            Vector2<double> pos;
            Vector2<double> size;
            Vector2<double> display_pos;
            Vector2<double> display_size;
        };

        Window() = delete;

        [[nodiscard]]
        const Viewport& getViewport() const;

    protected:

        Window(const Vector2<double>& size,
               const Vector2<double>& pos = {0, 0});

        /*--------------------------------------------------------------------*/

        template <typename SomeWindow, >

        /*--------------------------------------------------------------------*/

        virtual bool onRender();

        bool onMouseMove(MouseEvent& event) override;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseScroll(class MouseScrollEvent& event) override;

        Viewport viewport;

        friend class WindowManager;

    };

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
