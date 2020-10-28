/*============================================================================*/
#ifndef SHISHGL_SHAPED_WINDOW_HPP
#define SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/

/* TODO: use */
#include <type_traits>

#include "ShishGL/core/log.hpp"
#include "ShishGL/core/engine.hpp"
#include "ShishGL/core/window.hpp"
#include "ShishGL/utility/color.hpp"
/*----------------------------------------------------------------------------*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedWindow : public Window, public SomeShape {
    protected:

        Color color;
        bool is_mouse_inside;

    public:

        template<typename... Args>
        explicit ShapedWindow(Window* parent, const Color& color, Args&&... args)
            : Window(parent)
            , SomeShape(std::forward<Args>(args)...)
            , color(color)
            , is_mouse_inside(false) {

            if (parent) {
                SomeShape::translate(parent->getAbsPos());
            }

            if (SomeShape::contains(Engine::getMousePos())) {
                is_mouse_inside = true;
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

        /*====================================================================*/
        virtual void onMouseEntered(const Event*) { /* nothing */ }

        virtual void onMouseLeft(const Event*) { /* nothing */ }
        /*====================================================================*/

        void onRender() override {
            Engine::setColor(color);
            SomeShape::render();
        }

        bool getEvent(const Event* event) override {

            bool is_event_inside = SomeShape::contains(event->mouse.where);

            if (event->type == Event::MOUSE_MOVE) {

                if (is_mouse_inside && !is_event_inside) {

                    is_mouse_inside = false;
                    onMouseLeft(event);
                    return true;

                } else if (!is_mouse_inside && is_event_inside) {

                    is_mouse_inside = true;
                    onMouseEntered(event);
                    return true;

                }

                return Window::getEvent(event);

            } else if (event->type == Event::MOUSE_CLICK &&
                       event->mouse_button.state == Mouse::DOWN) {

                if (is_event_inside) {
                    return Window::getEvent(event);
                }

                return false;

            }

            return Window::getEvent(event);
        }
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/
