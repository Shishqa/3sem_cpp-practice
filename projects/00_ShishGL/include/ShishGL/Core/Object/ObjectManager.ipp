/*============================================================================*/
#ifndef SHISHGL_OBJECT_MANAGER_IPP
#define SHISHGL_OBJECT_MANAGER_IPP
/*============================================================================*/
namespace ShishGL {

    template<typename SomeObject>
    ObjectManager::Helper<SomeObject, SomeObject&>
    ObjectManager::get(Object::ID id)
    {
        return dynamic_cast<SomeObject &>(*Pool()[id]);
    }

    /*--------------------------------------------------------------------*/

    template<typename SomeObject, typename... Args>
    ObjectManager::Helper<SomeObject, Object::ID>
    ObjectManager::create(Args &&... args) {

        Object::ID new_id = newId();

        auto ptr = std::make_unique<SomeObject>(new_id, std::forward<Args>(args)...);

        /* todo: handle exceptions */
        Pool().try_emplace(new_id, std::move(ptr));

        return new_id;
    }

    /*------------------------------------------------------------------------*/

    template<typename SomeObject, typename... Args>
    inline Object::ID CREATE(Args &&... args) {
        return ObjectManager::create<SomeObject>(std::forward<Args>(args)...);
    }

    /*------------------------------------------------------------------------*/

    template<typename SomeObject>
    inline SomeObject &GET(Object::ID id) {
        return ObjectManager::get<SomeObject>(id);
    }

}
/*============================================================================*/
#endif //SHISHGL_OBJECT_MANAGER_IPP
/*============================================================================*/
