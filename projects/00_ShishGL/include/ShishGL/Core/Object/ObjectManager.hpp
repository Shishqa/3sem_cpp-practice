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

        template <typename SomeObject>
        static Helper<SomeObject, SomeObject&> get(Object::ID id);

        template <typename SomeObject, typename... Args>
        static Helper<SomeObject, Object::ID> create(Args&&... args);

        static bool remove(Object::ID id);

    private:

        using ObjectPool =
                std::unordered_map<Object::ID, std::unique_ptr<Object>>;

        static ObjectPool& Pool();

    };

    template <typename SomeObject, typename... Args>
    inline Object::ID CREATE(Args&&... args);

    template <typename SomeObject>
    inline SomeObject& GET(Object::ID id);

}
/*============================================================================*/
#include "ObjectManager.ipp"
/*============================================================================*/
#endif //SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
