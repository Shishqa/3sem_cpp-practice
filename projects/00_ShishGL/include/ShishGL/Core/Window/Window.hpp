/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <list>

#include "SubscriptionManager.hpp"
#include "PlatformListener.hpp"
#include "MouseEvent.hpp"
#include "EventSystem.hpp"
#include "Viewport.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public PlatformListener {
    public:

        Window() = delete;

        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;

        [[nodiscard]]
        const Viewport& getViewport() const;

        ~Window() override = default;

    protected:

        explicit Window(const Viewport& viewport);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        void setPos(const Vector2<double>& pos);

        void translate(const Vector2<double>& delta);

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const;

        /*--------------------------------------------------------------------*/

        virtual void onRender();

        virtual bool onMouseEntered(MouseEvent& event);

        virtual bool onMouseLeft(MouseEvent& event);

        bool onMouseMove(MouseEvent& event) override;

    private:

        void fit_parent();

        bool is_active;

        Viewport viewport;

        friend class WindowManager;

    };

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
