/*============================================================================*/
#ifndef SHISHGL_SHAPED_WINDOW_HPP
#define SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/

/* TODO: use */
#include <type_traits>

#include "ShishGL/core/window.hpp"
/*----------------------------------------------------------------------------*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedWindow : public Window, public SomeShape {
    protected:

        Color color;

    public:

        template<typename... Args>
        explicit ShapedWindow(Window* parent, const Color& color, Args&&... args)
            : Window(parent)
            , SomeShape(std::forward<Args>(args)...)
            , color(color) {

            if (parent) {
                SomeShape::translate(parent->getAbsPos());
            }

            LogSystem::printLog("Created shaped window %p at (%d; %d)",
                                reinterpret_cast<void*>(this),
                                SomeShape::getPos().x, SomeShape::getPos().y);
        }

        [[nodiscard]]
        Vector2<int> getAbsPos() override {
            return SomeShape::getPos();
        }

        [[nodiscard]]
        Vector2<int> getRelPos() override {
            if (!parent) {
                return getAbsPos();
            }
            return getAbsPos() - parent->getAbsPos();
        }

        ~ShapedWindow() override = default;

    protected:

        void onRender() override {
            Engine::setColor(color);
            SomeShape::render();
        }

        bool filterEvent(const Event* event) override {

            if (Event::MOUSE_MOVE == event->type ||
                Event::MOUSE_SCROLL == event->type ||
                Event::MOUSE_CLICK == event->type) {

                return (SomeShape::contains(event->mouse.where));
            }
            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/
