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

    class alignas(8) Window : public Object {
    protected:

        Window* parent;
        Vector2<int> rel_pos;
        Vector2<int> abs_pos;

    public:

        explicit Window(Window* parent, const Vector2<int>& pos = {0, 0});

        Window() = delete;

        ~Window() override;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<int>& getRelPos() const;

        [[nodiscard]]
        const Vector2<int>& getAbsPos() const;

        void refresh();

        virtual bool contains(const Vector2<int>&) { return false; }

    protected:

        friend class WindowContainer;

        bool getEvent(const Event* event) override;

        virtual void onRender() { /* nothing */ };

        virtual void onMouse(const MouseEvent*) { /* nothing */ }

        virtual void onKeyboard(const KeyboardEvent*) { /* nothing */ }

        virtual void onIdle(const TimerEvent*) { /* nothing */ }
    };

}
/*============================================================================*/
#endif //SHISHGL_ABSTRACT_WINDOW_HPP
/*============================================================================*/
