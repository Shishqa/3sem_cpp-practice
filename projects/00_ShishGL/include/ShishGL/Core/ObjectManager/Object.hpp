/*============================================================================*/
#ifndef SHISHGL_OBJECT_HPP
#define SHISHGL_OBJECT_HPP
/*============================================================================*/
#include <cstdint>
/*============================================================================*/
namespace ShishGL {

    class Event;

    class Object {
    public:

        using ID = uint64_t;

        /* NoCopyable */
        /*-----------------------------------------------*/
        Object(const Object& other) = delete;
        Object& operator=(const Object& other) = delete;
        /*-----------------------------------------------*/

        [[nodiscard]]
        const Object::ID& id() const;

        virtual ~Object() = default;

    protected:

        explicit Object(Object::ID id);

    private:

        Object::ID obj_id;

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_HPP
/*============================================================================*/
