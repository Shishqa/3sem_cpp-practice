/*============================================================================*/
#ifndef SHISHGL_HOLDABLE_WINDOW_HPP
#define SHISHGL_HOLDABLE_WINDOW_HPP
/*============================================================================*/
#include <cstdint>

#include "ClickableWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    class HoldableWindow : public ClickableWindow {
    public:

        explicit HoldableWindow(Shape2D* shape);

        ~HoldableWindow() override = default;

        bool onMouseButton(MouseButtonEvent& event) override;

        [[nodiscard]]
        bool isHeld() const;

        [[nodiscard]]
        uint8_t numHeld() const;

    private:

        uint8_t n_held;

    };

}
/*============================================================================*/
#endif //SHISHGL_HOLDABLE_WINDOW_HPP
/*============================================================================*/
