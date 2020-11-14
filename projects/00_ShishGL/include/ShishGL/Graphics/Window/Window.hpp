/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <type_traits>
#include <unordered_set>

#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
#include "PlatformListener.hpp"
#include "RenderSystem.hpp"
#include "MouseEvent.hpp"
#include "Shape2D.hpp"
#include "Viewport.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public Renderable, public PlatformListener {
    public:

        explicit Window(Object::ID id, Object::ID shape,
                        Object::ID parent = LayoutManager::ROOT);

        Window() = delete;

        /*--------------------------------------------------------------------*/

        virtual void initLayout() { }

        /*--------------------------------------------------------------------*/
        template <typename SomeWindow, typename SomeShape, typename... Args>
        Object::ID attach(Args&&... args);

        template <typename SomeWindow, typename SomeShape, typename... Args>
        Object::ID attachSubscribe(Args&&... args);

        bool detach(Object::ID subwindow);
        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Viewport& getViewport() const;

    protected:

        bool onRender() override;

        virtual bool onMouseEntered(MouseEvent&);

        virtual bool onMouseLeft(MouseEvent&);

        bool onMouseMove(MouseEvent& event) override;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseScroll(class MouseScrollEvent& event) override;

        [[nodiscard]]
        Shape2D& getShape() const;

    private:

        bool is_active;

        Viewport viewport;

        Object::ID shape;

        friend class WindowManager;

    };

}
/*============================================================================*/
#include "Window.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
