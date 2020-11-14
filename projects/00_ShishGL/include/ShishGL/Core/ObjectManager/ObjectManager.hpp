/*============================================================================*/
#ifndef SHISHGL_OBJECT_MANAGER_HPP
#define SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
#include <type_traits>
#include <memory>
#include <unordered_map>

#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class ObjectManager {
    private:

        template <typename SomeObject, typename T>
        using Helper =
                std::enable_if_t<std::is_base_of<Object, SomeObject>::value, T>;

        static Object::ID newId();

    public:

        static constexpr Object::ID ID_UNDEFINED = 0;

        template <typename SomeObject>
        static SomeObject& get(Object::ID id);

        template <typename SomeObject, typename... Args>
        static Helper<SomeObject, Object::ID> create(Args&&... args);

        static bool remove(Object::ID id);

    private:

        static bool pool_locked;

        using ObjectPool =
                std::unordered_map<Object::ID, Object*>;

        static ObjectPool& Pool();

        static void clear();

        friend class CoreApplication;

    };

    template <typename SomeObject, typename... Args>
    inline Object::ID CREATE(Args&&... args);

    void REMOVE(Object::ID id);

    template <typename SomeObject>
    inline SomeObject& GET(Object::ID id);

}
/*============================================================================*/
#include "ObjectManager.ipp"
/*============================================================================*/
#endif //SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
