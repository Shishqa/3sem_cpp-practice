/*============================================================================*/
#ifndef SHISHGL_SHAPED_BUTTON_HPP
#define SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
#include "shaped_window.hpp"
/*============================================================================*/
namespace ShishGL {

    struct ButtonColorScheme {
        Color normal, hover, click;
    };

    static constexpr ButtonColorScheme DEFAULT_BUTTON_COLORS = {
            SANDY_BROWN, SALMON, WHITE_SMOKE
    };

    template <typename SomeShape>
    class ShapedButton : public ShapedWindow<SomeShape> {
    protected:

        const ButtonColorScheme colorscheme;

    public:

        template <typename... Args>
        explicit ShapedButton(Window* parent, const ButtonColorScheme& colors,
                              Args&&... args)
            : ShapedWindow<SomeShape>(parent, colors.normal, std::forward<Args>(args)...)
            , colorscheme(colors) {}

        ~ShapedButton() override = default;

        virtual void reactOnClick() = 0;

        void onMouse(const Event* event) override {

            if (event->type == Event::MOUSE_CLICK &&
                event->mouse_button.button == Mouse::LEFT) {

                if (event->mouse_button.state == Mouse::DOWN) {
                    ShapedWindow<SomeShape>::color = colorscheme.click;

                    reactOnClick();

                } else {
                    ShapedWindow<SomeShape>::color = colorscheme.normal;
                }
            }
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_BUTTON_HPP
/*============================================================================*/
