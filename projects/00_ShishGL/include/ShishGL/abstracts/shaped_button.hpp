/*============================================================================*/
#ifndef SHISHGL_SHAPED_BUTTON_HPP
#define SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
#include "ShishGL/color/color_collection.hpp"
#include "shaped_window.hpp"
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

    template <typename SomeShape>
    class ShapedButton : public ShapedWindow<SomeShape> {
    protected:

        const ButtonColorScheme colorscheme;

        bool is_pressed;

    public:

        template <typename... Args>
        explicit ShapedButton(Window* parent, const ButtonColorScheme& colors,
                              Args&&... args)
            : ShapedWindow<SomeShape>(parent, colors.normal,
                                      std::forward<Args>(args)...)
            , colorscheme(colors)
            , is_pressed(false) {}

        ~ShapedButton() override = default;

    protected:

        virtual void reactOnButton(const MouseButtonEvent*) = 0;

        bool filterEvent(const Event* event) override {

            if (is_pressed) {
                return true;
            }

            if (event->type() == Event::MOUSE_BUTTON ||
                event->type() == Event::MOUSE_SCROLL) {

                auto mouse = dynamic_cast<const MouseEvent*>(event);
                if (!mouse) {
                    return false;
                }

                if (!ShapedWindow<SomeShape>::contains(mouse->where())) {
                    return false;
                }
            }

            return true;
        }

        bool onMouseClick(const MouseButtonEvent* event) override {
            if(event->button() == Mouse::LEFT) {
                if (event->state() == Mouse::DOWN) {

                    is_pressed = true;
                    reactOnButton(event);

                    ShapedWindow<SomeShape>::color = colorscheme.click;

                } else if (is_pressed) {

                    is_pressed = false;
                    reactOnButton(event);

                    if (ShapedWindow<SomeShape>::contains(event->where())) {
                        ShapedWindow<SomeShape>::color = colorscheme.hover;
                    } else {
                        ShapedWindow<SomeShape>::color = colorscheme.normal;
                    }
                }
            }
            return true;
        }

        bool onMouseEntered(const MouseEvent*) override {
            if (!is_pressed) {
                ShapedWindow<SomeShape>::color = colorscheme.hover;
            }
            return true;
        }

        bool onMouseLeft(const MouseEvent*) override {
            if (!is_pressed) {
                ShapedWindow<SomeShape>::color = colorscheme.normal;
            }
            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
