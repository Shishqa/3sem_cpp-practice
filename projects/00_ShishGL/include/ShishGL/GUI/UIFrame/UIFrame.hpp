/*============================================================================*/
#ifndef SHISHGL_UI_FRAME_HPP
#define SHISHGL_UI_FRAME_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
/*============================================================================*/
namespace ShishGL {

    class UIFrame : public UIWindow {
    protected:

        explicit UIFrame(const Viewport& viewport);

        void attach(Window* child) override;

        void detach(Window* child) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
