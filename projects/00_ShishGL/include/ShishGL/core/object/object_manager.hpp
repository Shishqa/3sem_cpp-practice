/*============================================================================*/
#ifndef SHISHGL_OBJECT_MANAGER_HPP
#define SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
#include <type_traits>
#include <memory>
#include <unordered_map>

#include "object.hpp"
/*============================================================================*/
namespace ShishGL {

    class ObjectManager {
    private:

        template <typename SomeObject, typename T>
        using Helper =
                std::enable_if_t<std::is_base_of<Object, SomeObject>::value, T>;

        /*--------------------------------------------------------------------*/

        static Object::ID newId() {
            /* todo: something smarter */
            static Object::ID MIN_AVAILABLE_ID = 200;
            return MIN_AVAILABLE_ID++;
        }

        /*--------------------------------------------------------------------*/

    public:

        template <typename SomeObject, typename... Args>
        static Helper<SomeObject, Object::ID> create(Args&&... args) {

            Object::ID new_id = newId();

            auto ptr = std::make_unique<SomeObject>(new_id, std::forward<Args>(args)...);

            /* todo: handle exceptions */
            Pool().try_emplace(new_id, std::move(ptr));

            return new_id;
        }

        /*--------------------------------------------------------------------*/

        static bool remove(Object::ID id) {
            return Pool().erase(id);
        }

        /*--------------------------------------------------------------------*/

        template <typename SomeObject>
        static Helper<SomeObject, SomeObject&> get(Object::ID id) {
            return dynamic_cast<SomeObject&>(*Pool()[id]);
        }

    private:

        friend class EventSystem;
        friend class Window;

        /*----------------------------------------------------------------*/
        static Object& get(Object::ID id) {
            return *Pool()[id];
        }
        /*----------------------------------------------------------------*/

        using ObjectPool =
                std::unordered_map<Object::ID, std::unique_ptr<Object>>;

        static ObjectPool& Pool() {
            static ObjectPool POOL;
            return POOL;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_MANAGER_HPP
/*============================================================================*/
