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

        [[nodiscard]]
        Object::ID id() const { return m_id; }

        virtual ~Object() = default;

    protected:

        /* Creates Objects */
        /*-------------------------------------------------------*/
        friend class ObjectManager;

        explicit Object(Object::ID id) : m_id(id) {};
        /*-------------------------------------------------------*/

        /* Delivers Events */
        /*-------------------------------------------------------*/
        friend class Event;
        friend class EventSystem;

        virtual bool filterEvent(class Event&) const { return true; }

        virtual bool unhandledEvent(class Event&) { return false; }
        /*-------------------------------------------------------*/

        /* System Event handlers */
        /*-------------------------------------------------------*/
        friend class MouseEvent;
        virtual bool onMouseMove(class MouseEvent&) { return false; }

        friend class MouseButtonEvent;
        virtual bool onMouseClick(class MouseButtonEvent&) { return false; }

        friend class MouseScrollEvent;
        virtual bool onMouseScroll(class MouseScrollEvent&) { return false; }

        friend class KeyboardEvent;
        virtual bool onKeyboard(class KeyboardEvent&) { return false; }

        friend class TimerEvent;
        virtual bool onTimer(class TimerEvent&) { return false; }
        /*-------------------------------------------------------*/

    private:

        Object::ID m_id;

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
