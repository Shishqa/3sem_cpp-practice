/*============================================================================*/
#ifndef SHISHGL_SHAPED_BUTTON_HPP
#define SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
#include "ShishGL/utility/color_collection.hpp"
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

        virtual void reactOnClick(const Event*) = 0;
        virtual void reactOnRelease(const Event*) = 0;

        void onMouseClick(const Event* event) override {

            if (!ShapedWindow<SomeShape>::contains(event->mouse.where) &&
                event->mouse_button.state == Mouse::DOWN) {
                return;
            }

            if(event->mouse_button.button == Mouse::LEFT) {
                if (event->mouse_button.state == Mouse::DOWN) {

                    is_pressed = true;
                    reactOnClick(event);

                    ShapedWindow<SomeShape>::color = colorscheme.click;

                } else if (is_pressed) {

                    is_pressed = false;
                    reactOnRelease(event);

                    if (ShapedWindow<SomeShape>::contains(event->mouse.where)) {
                        ShapedWindow<SomeShape>::color = colorscheme.hover;
                    } else {
                        ShapedWindow<SomeShape>::color = colorscheme.normal;
                    }
                }
            }
        }

        void onMouseEntered(const Event*) override {
            if (!is_pressed) {
                ShapedWindow<SomeShape>::color = colorscheme.hover;
            }
        }

        void onMouseLeft(const Event*) override {
            if (!is_pressed) {
                ShapedWindow<SomeShape>::color = colorscheme.normal;
            }
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
