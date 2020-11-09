/*============================================================================*/
#ifndef SHISHGL_SHAPED_WINDOW_HPP
#define SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/

/* TODO: use */
#include <type_traits>

#include "ShishGL/core/log.hpp"
#include "ShishGL/core/engine/template_engine.hpp"
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/color/color.hpp"
/*----------------------------------------------------------------------------*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedWindow : public Window, public SomeShape {
    protected:

        Color color;
        bool is_mouse_inside;

    public:

        template<typename... Args>
        explicit ShapedWindow(Object::ID id, Object::ID parent, const Color& color, Args&&... args)
            : Window(id, parent)
            , SomeShape(std::forward<Args>(args)...)
            , color(color)
            , is_mouse_inside(false) {

            if (parent) {
                SomeShape::translate(ObjectManager::get<Window>(parent).getAbsPos());
            }

            if (SomeShape::contains(Engine::getMousePos())) {
                is_mouse_inside = true;
            }

            LogSystem::printLog("Created shaped window %p at (%lg; %lg)",
                                reinterpret_cast<void*>(this),
                                SomeShape::getPos().x, SomeShape::getPos().y);
        }

        [[nodiscard]]
        Vector2<double> getAbsPos() override {
            return SomeShape::getPos();
        }

        [[nodiscard]]
        Vector2<double> getRelPos() override {
            if (!parent) {
                return getAbsPos();
            }
            return getAbsPos() - ObjectManager::get<Window>(parent).getAbsPos();
        }

        ~ShapedWindow() override = default;

    protected:

        /*====================================================================*/
        virtual bool onMouseEntered(const MouseEvent*) { return false; }

        virtual bool onMouseLeft(const MouseEvent*) { return false; }
        /*====================================================================*/

        void onRender() override {
            Engine::setColor(color);
            SomeShape::render();
        }

        bool getEvent(const Event* event) override {
            if (Event::MOUSE_MOVE == event->type()) {

                auto m_event = dynamic_cast<const MouseEvent*>(event);
                if (!m_event) {
                    return false;
                }

                bool is_event_inside = SomeShape::contains(m_event->where());

                if (is_mouse_inside && !is_event_inside) {

                    is_mouse_inside = false;
                    return onMouseLeft(m_event);

                } else if (!is_mouse_inside && is_event_inside) {

                    is_mouse_inside = true;
                    return onMouseEntered(m_event);

                }
            }

            return Window::getEvent(event);
        }
    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/
