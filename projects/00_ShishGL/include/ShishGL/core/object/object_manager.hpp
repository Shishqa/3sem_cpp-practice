/*============================================================================*/
#ifndef SHISHGL_OBJECT_MANAGER_HPP
#define SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
#include <type_traits>
#include <memory>
#include <unordered_map>

#include "object.hpp"
#include "ShishGL/core/core_application.hpp"
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
        static Helper<SomeObject, SomeObject&> get(Object::ID id) {
            return dynamic_cast<SomeObject&>(*Pool()[id]);
        }

        /*--------------------------------------------------------------------*/
        template <typename SomeObject, typename... Args>
        static Helper<SomeObject, Object::ID> create(Args&&... args) {

            if (!CoreApplication::is_initialized) {
                return 0;
            }

            Object::ID new_id = newId();

            auto ptr = std::make_unique<SomeObject>(new_id, std::forward<Args>(args)...);

            /* todo: handle exceptions */
            Pool().try_emplace(new_id, std::move(ptr));

            return new_id;
        }

        static bool remove(Object::ID id);
        /*--------------------------------------------------------------------*/

    private:

        using ObjectPool =
                std::unordered_map<Object::ID, std::unique_ptr<Object>>;

        static ObjectPool& Pool();

    };

    template <typename SomeObject, typename... Args>
    inline Object::ID CREATE(Args&&... args) {
        return ObjectManager::create<SomeObject>(std::forward<Args>(args)...);
    }

    template <typename SomeObject>
    inline SomeObject& GET(Object::ID id) {
        return ObjectManager::get<SomeObject>(id);
    }

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
