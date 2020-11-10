/*============================================================================*/
#ifndef SHISHGL_SHAPED_FLOAT_HPP
#define SHISHGL_SHAPED_FLOAT_HPP
/*============================================================================*/
#include "shaped_button.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    class ShapedFloat : public ShapedButton<SomeShape> {
    protected:

        Vector2<double> where_dragged = {};

    public:

        template <typename... Args>
        explicit ShapedFloat(Object::ID id, Object::ID parent, const ButtonColorScheme& colors,
                             Args&&... args)
                : ShapedButton<SomeShape>(id, parent, colors,
                                          std::forward<Args>(args)...) {

                    SubscriptionManager::subscribe(SystemEvents::SYSTEM, ShapedButton<SomeShape>::id());

                    LogSystem::printLog("Created shaped float");

                }

        ~ShapedFloat() override = default;

    protected:

        void reactOnButton(MouseButtonEvent& event) override {
            if (event.state() == Mouse::DOWN) {
                where_dragged = event.where();
            }
        }

        bool onMouseMove(MouseEvent& event) override {
            if (ShapedButton<SomeShape>::is_pressed) {
                ShapedWindow<SomeShape>::translate(event.where() - where_dragged);
                where_dragged = event.where();
                return true;
            }
            return ShapedButton<SomeShape>::onMouseMove(event);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_FLOAT_HPP
/*============================================================================*/
