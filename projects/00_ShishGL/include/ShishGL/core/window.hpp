/*============================================================================*/
#ifndef SHISHGL_ABSTRACT_WINDOW_HPP
#define SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
#include <cstddef>

#include "object.hpp"
#include "event.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class Window : public Object {
    protected:

        Window* parent;

    public:

        explicit Window(Window* parent = nullptr);

        Window() = delete;

        ~Window() override = default;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual Vector2<int> getRelPos() = 0;

        [[nodiscard]]
        virtual Vector2<int> getAbsPos() = 0;

        void refresh();

    protected:

        friend class WindowContainer;

        bool getEvent(const Event* event) override;

        virtual void onRender() = 0;
    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
