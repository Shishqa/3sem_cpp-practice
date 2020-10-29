/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
#include "ShishGL/core/event/event.hpp"
/*============================================================================*/
namespace ShishGL {

    class Object {
    public:

        Object(const Object& other) = delete;

        Object& operator=(const Object& other) = delete;

        virtual ~Object() = default;

    protected:

        Object() = default;

        virtual bool filterEvent(const Event* event);

        virtual bool getEvent(const Event* event);

        virtual bool onMouseMove(const MouseEvent* event);

        virtual bool onMouseClick(const MouseButtonEvent* event);

        virtual bool onMouseScroll(const MouseScrollEvent* event);

        virtual bool onKeyboard(const KeyboardEvent* event);

        friend class EventSystem;
        friend class CoreApplication;
    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
