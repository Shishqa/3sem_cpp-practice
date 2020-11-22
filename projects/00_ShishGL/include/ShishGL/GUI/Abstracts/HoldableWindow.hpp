/*============================================================================*/
#ifndef SHISHGL_HOLDABLE_WINDOW_HPP
#define SHISHGL_HOLDABLE_WINDOW_HPP
/*============================================================================*/
#include <cstdint>

#include "ClickableWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    class HoldableWindow : public ClickableWindow<Shape> {
    public:

        template <typename... Args>
        HoldableWindow(Object::ID id, Object::ID parent, Args&&... args);

        ~HoldableWindow() override = default;

        bool onMouseButton(MouseButtonEvent& event) override;

        [[nodiscard]]
        inline bool isHolded() const;

        [[nodiscard]]
        inline uint8_t numHolded() const;

    private:

        uint8_t n_holded;

    };

}
/*============================================================================*/
#include "../../../../src/GUI/Interactables/HoldableWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_HOLDABLE_WINDOW_HPP
/*============================================================================*/
