/*============================================================================*/
#ifndef SHISHGL_SYSTEM_OBJECT_HPP
#define SHISHGL_SYSTEM_OBJECT_HPP
/*============================================================================*/
#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class SystemObject : public Object {
    public:

        explicit SystemObject(Object::ID id);

        ~SystemObject() override = default;

    protected:

        /*---------------------------------------------------------*/
        virtual bool onMouseMove(class MouseEvent&);

        virtual bool onMouseButton(class MouseButtonEvent&);

        virtual bool onMouseScroll(class MouseScrollEvent&);

        virtual bool onKeyboard(class KeyboardEvent&);

        virtual bool onTimer(class TimerEvent&);
        /*---------------------------------------------------------*/

        friend class MouseEvent;
        friend class MouseButtonEvent;
        friend class MouseScrollEvent;
        friend class KeyboardEvent;
        friend class TimerEvent;

    };

}
/*============================================================================*/
#endif //SHISHGL_SYSTEM_OBJECT_HPP
/*============================================================================*/
