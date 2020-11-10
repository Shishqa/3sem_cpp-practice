/*============================================================================*/
#include "ShishGL/core/object/object_manager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

ObjectManager::ObjectPool& ObjectManager::Pool() {
    static ObjectPool POOL;
    return POOL;
}

/*----------------------------------------------------------------------------*/

Object::ID ObjectManager::newId() {
    /* todo: something smarter */
    static Object::ID MIN_AVAILABLE_ID = 200;
    return MIN_AVAILABLE_ID++;
}

/*----------------------------------------------------------------------------*/

bool ObjectManager::remove(Object::ID id) {
    return Pool().erase(id);
}

/*============================================================================*/