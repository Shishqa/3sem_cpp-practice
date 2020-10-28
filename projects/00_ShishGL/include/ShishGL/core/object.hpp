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

        virtual bool filterEvent(const Event*) { return true; }

        virtual bool getEvent(const Event* event);

        virtual void onMouseMove(const Event*) { /* nothing */ }

        virtual void onMouseClick(const Event*) { /* nothing */ }

        virtual void onMouseScroll(const Event*) { /* nothing */ }

        virtual void onKeyboard(const Event*) { /* nothing */ }

        virtual void onIdle(const Event*) { /* nothing */ }

        friend class EventSystem;
    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
