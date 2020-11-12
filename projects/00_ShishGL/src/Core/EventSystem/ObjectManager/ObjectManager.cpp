/*============================================================================*/
#include "LogSystem.hpp"
#include "ObjectManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool ObjectManager::pool_locked = false;

/*----------------------------------------------------------------------------*/

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

    if (pool_locked) {
        return false;
    }

    bool status = Pool().erase(id);
    if (status) {
        LogSystem::printLog("Removed Object with id %lu", id);
    } else {
        LogSystem::printWarning("Could not remove Object by id %lu", id);
    }
    return status;
}

/*----------------------------------------------------------------------------*/

void ObjectManager::clear() {
    LogSystem::printLog("Removing objects...");
    pool_locked = true;
    Pool().clear();
    pool_locked = false;
    LogSystem::printLog("Objects removed");
}

/*----------------------------------------------------------------------------*/

void ShishGL::REMOVE(Object::ID id) {
    ObjectManager::remove(id);
}

/*============================================================================*/