/*============================================================================*/
#include <cstdio>

#include "WindowManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowManager::RenderLayout& WindowManager::Layout() {
    static RenderLayout LAYOUT;
    return LAYOUT;
}

/*----------------------------------------------------------------------------*/

Window* WindowManager::getParent(Window* win) {
    return Layout()[win].parent;
}

/*----------------------------------------------------------------------------*/

const WindowManager::RenderLayout& WindowManager::getLayout() {
    return Layout();
}

/*----------------------------------------------------------------------------*/

void WindowManager::putRoot(Window* window) {
    Layout()[Layout()[window].parent].children.remove(window);
    Layout()[ROOT].children.push_back(window);
    Layout()[window].parent = ROOT;

    window->fit_parent();
}

/*----------------------------------------------------------------------------*/

void WindowManager::attach(Window* parent, Window* child) {
    Layout()[Layout()[child].parent].children.remove(child);
    Layout()[parent].children.push_back(child);
    Layout()[child].parent = parent;

    child->fit_parent();
}

/*----------------------------------------------------------------------------*/

void WindowManager::detach(Window* child) {
    Layout()[Layout()[child].parent].children.remove(child);
}

/*----------------------------------------------------------------------------*/

void WindowManager::clear() {
    clear(ROOT);
}

/*----------------------------------------------------------------------------*/

void WindowManager::clear(Window* root) {
    for (auto& child : Layout()[root].children) {
        clear(child);
        delete child;
    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::refresh() {
    RENDERER().clear({0, 0, 0, 255});
    refresh(ROOT);
    RENDERER().display();
}

/*----------------------------------------------------------------------------*/

void WindowManager::refresh(Window* root) {
    for (auto& child : Layout()[root].children) {
        RENDERER().setViewport(child->viewport.pos,
                               child->viewport.size,
                               child->viewport.display_pos,
                               child->viewport.display_size);
        child->onRender();
        refresh(child);
    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n");
    dump(file, ROOT);
    fprintf(file, "}\n");

    fclose(file);
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(FILE* file, Window* root) {

    for (auto& child : Layout()[root].children) {
        fprintf(file, "%p -> %p\n",
                reinterpret_cast<void*>(root),
                reinterpret_cast<void*>(child));
        dump(file, child);
    }
}

/*============================================================================*/