/*============================================================================*/
#ifndef SHISHGL_SHAPED_WINDOW_HPP
#define SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/

/* TODO: use */
#include <type_traits>

#include "ShishGL/Core/log.hpp"
#include "ShishGL/core/engine/template_engine.hpp"
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/Core/Platform/Primitives/Color.hpp"
#include "EventSystem/SubscriptionManager.hpp"
#include "ShishGL/core/event/system_slots.hpp"
#include "ShishGL/core/event/event.hpp"
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

            SubscriptionManager::subscribe(SystemEvents::SYSTEM, Window::id());

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
        virtual bool onMouseEntered(MouseEvent&) { return false; }

        virtual bool onMouseLeft(MouseEvent&) { return false; }
        /*====================================================================*/

        bool onRender() override {
            Engine::setColor(color);
            SomeShape::render();
            return true;
        }

        bool onMouseMove(MouseEvent& event) override {

            bool is_event_inside = SomeShape::contains(event.where());

            if (is_mouse_inside && !is_event_inside) {

                is_mouse_inside = false;
                return this->onMouseLeft(event);

            } else if (!is_mouse_inside && is_event_inside) {

                is_mouse_inside = true;
                return this->onMouseEntered(event);

            }

            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/
