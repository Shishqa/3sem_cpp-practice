/*============================================================================*/
#include <cstdio>

#include "LayoutManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

LayoutManager::RenderLayout& LayoutManager::Layout() {
    static RenderLayout LAYOUT;
    return LAYOUT;
}

/*----------------------------------------------------------------------------*/

Renderable::ID LayoutManager::getParent(Renderable::ID obj) {
    return Layout()[obj].parent;
}

/*----------------------------------------------------------------------------*/

const LayoutManager::RenderLayout& LayoutManager::getLayout() {
    return Layout();
}

/*----------------------------------------------------------------------------*/

void LayoutManager::putRoot(Object::ID object) {
    Layout()[ROOT].children.push_back(object);
    Layout()[object].parent = ROOT;
}

/*----------------------------------------------------------------------------*/

void LayoutManager::attach(Object::ID parent, Object::ID child) {
    Layout()[parent].children.push_back(child);
    Layout()[child].parent = parent;
}

/*----------------------------------------------------------------------------*/

void LayoutManager::detach(Object::ID parent, Object::ID child) {
    Layout()[parent].children.remove(child);
}

/*----------------------------------------------------------------------------*/

void LayoutManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n");
    dump(file, ROOT);
    fprintf(file, "}\n");

    fclose(file);
}

/*----------------------------------------------------------------------------*/

void LayoutManager::dump(FILE* file, Object::ID root) {

    for (auto& child : Layout()[root].children) {
        fprintf(file, "%lu -> %lu\n", root, child);
        dump(file, child);
    }

}

/*============================================================================*/