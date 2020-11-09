/*============================================================================*/
#ifndef SHISHGL_SHAPED_HOLDABLE_BUTTON_HPP
#define SHISHGL_SHAPED_HOLDABLE_BUTTON_HPP
/*============================================================================*/
#include "shaped_button.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedHoldableButton : public ShapedButton<SomeShape> {
    public:

        template <typename... Args>
        ShapedHoldableButton(Object::ID id, Object::ID parent, const ButtonColorScheme& colors,
                             Args&&... args)
            : ShapedButton<SomeShape>(id, parent, colors, std::forward<Args>(args)...) {}

        ~ShapedHoldableButton() override = default;

    protected:

        virtual void reactOnHold(const TimerEvent*) {};

        bool onTimer(const TimerEvent* event) override {
            if (ShapedButton<SomeShape>::is_pressed) {
                this->reactOnHold(event);
                return true;
            }
            return false;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_HOLDABLE_BUTTON_HPP
/*============================================================================*/
