/*============================================================================*/
#ifndef SHISHGL_CLICKABLE_WINDOW_HPP
#define SHISHGL_CLICKABLE_WINDOW_HPP
/*============================================================================*/
#include "Window.hpp"
#include "MouseEvent.hpp"
/*============================================================================*/
namespace ShishGL {

    class ClickableWindow : public Window {
    public:

        explicit ClickableWindow(Shape2D* shape);

        ~ClickableWindow() override = default;

        [[nodiscard]]
        bool filterEvent(Event& event) const override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CLICKABLE_WINDOW_HPP
/*============================================================================*/
