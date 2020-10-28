/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
namespace ShishGL {

    struct Event;

    class Object {
    public:

        Object() = default;
        virtual ~Object() = default;

    protected:

        virtual bool filterEvent(const Event*) { return false; }

        virtual bool getEvent(const Event* event);

        virtual void onMouse(const Event*) { /* nothing */ }

        virtual void onKeyboard(const Event*) { /* nothing */ }

        virtual void onIdle(const Event*) { /* nothing */ }

        friend class EventSystem;
    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
