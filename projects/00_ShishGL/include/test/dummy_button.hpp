/*============================================================================*/
#ifndef SHISHGL_DUMMY_BUTTON_HPP
#define SHISHGL_DUMMY_BUTTON_HPP
/*============================================================================*/
#include "ShishGL/window/shaped_button.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class DummyButton : public ShapedButton<SomeShape> {
    public:

        template <typename... Args>
        explicit DummyButton(Window* parent, Args&&... args)
            : ShapedButton<SomeShape>(parent, DEFAULT_BUTTON_COLORS,
                                      std::forward<Args>(args)...) {}

        void reactOnClick() override {
            LogSystem::printLog("I AM CLICKED!");
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_DUMMY_BUTTON_HPP
/*============================================================================*/
