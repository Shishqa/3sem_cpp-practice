/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
namespace ShishGL {

    struct Event;

    class alignas(8) Object {
    public:

        Object() = default;
        virtual ~Object() = default;

    protected:

        virtual bool getEvent(const Event*) = 0;

        friend class EventSystem;
    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
