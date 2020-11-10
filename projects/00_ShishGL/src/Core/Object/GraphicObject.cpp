/*============================================================================*/
#include "ShishGL/core/object/window.hpp"
#include "ShishGL/Core/Log/Log.hpp"
#include "ShishGL/core/event/base_event.hpp"
#include "ShishGL/Core/Event/EventSystem.hpp"
#include "ShishGL/Core/Event/SubscriptionManager.hpp"
#include "ShishGL/core/event/system_slots.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Window::Window(Object::ID id, Object::ID parent)
        : Object(id)
        , parent(parent) {

    SubscriptionManager::subscribe(SystemEvents::RENDER, Object::id());

    LogSystem::printLog("Created window %lu (parent=%lu)", id, parent);

}

/*----------------------------------------------------------------------------*/

Window::~Window() {
    for (const auto& sub_win : subwindows) {
        ObjectManager::remove(sub_win);
    }
}

/*----------------------------------------------------------------------------*/

void Window::refresh() {
    this->onRender();
}

/*----------------------------------------------------------------------------*/

bool Window::detach(Object::ID id) {
    return subwindows.erase(id);
}

/*============================================================================*/
