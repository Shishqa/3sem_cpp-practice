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
        explicit ShapedButton(Object::ID id, Object::ID parent, const ButtonColorScheme& colors,
                              Args&&... args)
            : ShapedWindow<SomeShape>(id, parent, colors.normal,
                                      std::forward<Args>(args)...)
            , colorscheme(colors)
            , is_pressed(false) {

                LogSystem::printLog("Created shaped button");

            }

        ~ShapedButton() override = default;

    protected:

        virtual void reactOnButton(MouseButtonEvent&) {}

        bool onMouseClick(MouseButtonEvent& event) override {
            if(event.button() == Mouse::LEFT) {
                if (event.state() == Mouse::DOWN) {

                    if (ShapedWindow<SomeShape>::is_mouse_inside) {
                        is_pressed = true;
                        reactOnButton(event);
                        ShapedWindow<SomeShape>::color = colorscheme.click;
                    }

                } else if (is_pressed) {

                    is_pressed = false;

                    if (ShapedWindow<SomeShape>::is_mouse_inside) {
                        reactOnButton(event);
                        ShapedWindow<SomeShape>::color = colorscheme.hover;
                    } else {
                        ShapedWindow<SomeShape>::color = colorscheme.normal;
                    }
                }
            }
            return ShapedWindow<SomeShape>::onMouseClick(event);
        }

        bool onMouseEntered(MouseEvent&) override {
            if (!is_pressed) {
                ShapedWindow<SomeShape>::color = colorscheme.hover;
            }
            return true;
        }

        bool onMouseLeft(MouseEvent&) override {
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
