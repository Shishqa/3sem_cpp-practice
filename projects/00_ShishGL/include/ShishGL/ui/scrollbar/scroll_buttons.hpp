/*============================================================================*/
#ifndef SHISHGL_SCROLL_BUTTONS_HPP
#define SHISHGL_SCROLL_BUTTONS_HPP
/*============================================================================*/
#include "ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    class ScrollUpButton : public RectButton {
    public:

        ScrollUpButton(Window* parent, const ButtonColorScheme& colors,
                       const Vector2<int>& pos,
                       const Vector2<size_t>& size);

        ~ScrollUpButton() override = default;

    protected:

        void reactOnClick(const Event* event) override;


    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLL_BUTTONS_HPP
/*============================================================================*/
