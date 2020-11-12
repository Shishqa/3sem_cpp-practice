/*============================================================================*/
#include "LayoutManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

LayoutManager::RenderLayout& LayoutManager::Layout() {
    static RenderLayout LAYOUT;
    return LAYOUT;
}

/*----------------------------------------------------------------------------*/

const LayoutManager::RenderLayout& LayoutManager::getLayout() {
    return Layout();
}

/*----------------------------------------------------------------------------*/

void LayoutManager::putOnTop(Object::ID id) {
    Layout().push_back(id);
}

/*============================================================================*/