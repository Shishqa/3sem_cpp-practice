/*============================================================================*/
#ifndef SHISHGL_OBJECT_MANAGER_IPP
#define SHISHGL_OBJECT_MANAGER_IPP
/*============================================================================*/
#include <stdexcept>

#include "LogSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    template<typename SomeObject>
    SomeObject&
    ObjectManager::get(Object::ID id)
    {
        if (!Pool().count(id)) {
            throw std::runtime_error("Error: Reference to unexisting object");
        }
        return dynamic_cast<SomeObject &>(*Pool()[id]);
    }

    /*--------------------------------------------------------------------*/

    template<typename SomeObject, typename... Args>
    ObjectManager::Helper<SomeObject, Object::ID>
    ObjectManager::create(Args &&... args) {

        Object::ID new_id = newId();

        if (Pool().count(new_id)) {
            LogSystem::printError("Trying to create Object with already used id %lu", new_id);
            return ID_UNDEFINED;
        }

        Pool()[new_id] = new SomeObject(new_id, std::forward<Args>(args)...);

        LogSystem::printLog("Created new Object with id %lu", new_id);

        return new_id;
    }

    /*------------------------------------------------------------------------*/

    template<typename SomeObject, typename... Args>
    inline Object::ID CREATE(Args&&... args) {
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
