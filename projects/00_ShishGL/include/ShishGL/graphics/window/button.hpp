/*============================================================================*/
#ifndef SHISHGL_SHAPED_BUTTON_HPP
#define SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
#include "ShishGL/graphics/color_collection.hpp"
#include "window.hpp"
/*============================================================================*/
namespace ShishGL {

    /*========================================================================*/
    struct ButtonColorScheme {
        Color normal, hover, click;
    };
    /*------------------------------------------------------------------------*/
    static constexpr ButtonColorScheme DEFAULT_BUTTON_COLORS = {
            SANDY_BROWN, SALMON, WHITE_SMOKE
    };
    /*========================================================================*/

    class Button : public Window {
    protected:

        uint8_t num_pressed;

    public:

        template <typename... Args>
        explicit Button(Window* parent, Args&&... args)
            : Window(parent, std::forward<Args>(args)...)
            , num_pressed(0) {}

        ~Button() override = default;

        bool filterEvent(const Event* event) override;

        virtual void reactOnButton(const MouseButtonEvent*) { /* nothing */ }

        virtual void reactOnHold(const TimerEvent*) { /* nothing */ }

        bool onMouseClick(const MouseButtonEvent* event) override;

        bool onTimer(const TimerEvent*) override;
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
