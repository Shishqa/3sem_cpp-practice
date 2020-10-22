/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
namespace ShishGL {

    class Event;

    class Object {
    public:

        Object() = default;
        virtual ~Object() = default;

    protected:

        virtual bool getEvent(const Event*) { return false; }

        friend class EventSystem;
    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
