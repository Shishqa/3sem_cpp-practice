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
        virtual Object::ID id() const;

        virtual ~Object();

    protected:

        explicit Object(Object::ID id);

        [[nodiscard]]
        virtual bool filterEvent(class Event&) const;

        [[nodiscard]]
        virtual bool onEvent(class Event&);

        friend class ObjectManager;
        friend class EventSystem;
        friend class Event;

    private:

        Object::ID obj_id;

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
