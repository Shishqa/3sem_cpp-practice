/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_HPP
#define SHISHGL_UI_WINDOW_HPP
/*============================================================================*/
#include "Window.hpp"
#include "Style.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class UIWindow : public Window {
    public:

        using Shape = SomeShape;

        template <typename SomeStyle, typename... Args>
        void applyStyle(Args&&... args);

        ~UIWindow() override;

    protected:

        explicit UIWindow(const Viewport& viewport);


        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        void onRender() override;

    private:

        std::list<Style*> styles;

        friend class WindowManager;

    };

}
/*============================================================================*/
#include "UIWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_HPP
/*============================================================================*/