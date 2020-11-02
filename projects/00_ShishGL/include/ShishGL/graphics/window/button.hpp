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

        const ButtonColorScheme colorscheme;
        bool is_pressed;

    public:

        template <typename... Args>
        explicit Button(Window* parent, const ButtonColorScheme& colors,
                        Args&&... args)
            : Window(parent, colors.normal, std::forward<Args>(args)...)
            , colorscheme(colors)
            , is_pressed(false) {}

        ~Button() override = default;

    protected:

        virtual void reactOnButton(const MouseButtonEvent*) { /* nothing */ }

        virtual void reactOnHold(const TimerEvent*) { /* nothing */ }
//
//        bool filterEvent(const Event* event) override {
//
//            if (is_pressed) {
//                return true;
//            }
//
//            if (event->type() == Event::MOUSE_BUTTON ||
//                event->type() == Event::MOUSE_SCROLL) {
//
//                auto mouse = dynamic_cast<const MouseEvent*>(event);
//                if (!mouse) {
//                    return false;
//                }
//
//                if (!ShapedWindow<SomeShape>::contains(mouse->where())) {
//                    return false;
//                }
//            }
//
//            return true;
//        }

        bool onMouseClick(const MouseButtonEvent* event) override;

        void onMouseEnter(const MouseEvent*) override;

        void onMouseLeave(const MouseEvent*) override;

        bool onTimer(const TimerEvent*) override;
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
