/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Object {
    public:

        using ID = uint64_t;

        /* NoCopyable */
        /*-----------------------------------------------*/
        Object(const Object& other) = delete;
        Object& operator=(const Object& other) = delete;
        /*-----------------------------------------------*/

        [[nodiscard]] Object::ID id() const;

        virtual ~Object() = default;

    protected:

        explicit Object(Object::ID id);

        virtual bool filterEvent(class Event&) const;

        virtual bool unhandledEvent(class Event&);
        /*-------------------------------------------------------*/

        /* System Event handlers */
        /*-------------------------------------------------------*/
        virtual bool onMouseMove(class MouseEvent&);

        virtual bool onMouseClick(class MouseButtonEvent&);

        virtual bool onMouseScroll(class MouseScrollEvent&);

        virtual bool onKeyboard(class KeyboardEvent&);

        virtual bool onTimer(class TimerEvent&);
        /*-------------------------------------------------------*/

        friend class ObjectManager;

        friend class Event;
        friend class EventSystem;

        friend class MouseEvent;
        friend class MouseButtonEvent;
        friend class MouseScrollEvent;
        friend class KeyboardEvent;
        friend class TimerEvent;

    private:

        Object::ID m_id;

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
