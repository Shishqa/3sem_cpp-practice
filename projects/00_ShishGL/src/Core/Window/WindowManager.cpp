/*============================================================================*/
#include <cstdio>

#include "WindowManager.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

WindowManager::RenderLayout& WindowManager::Layout() {
    static RenderLayout LAYOUT;
    return LAYOUT;
}

/*----------------------------------------------------------------------------*/

WindowManager::WindowPool& WindowManager::Pool() {
    static WindowPool POOL;
    return POOL;
}

/*============================================================================*/

Window* WindowManager::getParent(Window* win) {
    return Layout()[win].parent;
}

/*----------------------------------------------------------------------------*/

void WindowManager::putRoot(Window* window) {
    attach(ROOT, window);
}

/*----------------------------------------------------------------------------*/

void WindowManager::attach(Window* parent, Window* child) {

    Layout()[Layout()[child].parent].children.remove(child);
    Layout()[parent].children.push_back(child);
    Layout()[child].parent = parent;

    child->fit_parent();
    if (parent) {
        child->translate(parent->getPos());
    }

    SubscriptionManager::subscribe(parent, child);
}

/*----------------------------------------------------------------------------*/

void WindowManager::detach(Window* child) {
    Layout()[Layout()[child].parent].children.remove(child);
}

/*----------------------------------------------------------------------------*/

void WindowManager::clear() {
    for (auto& win : Pool()) {
        delete win;
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

        Viewport to_set = Layout()[child].to_set;

        RENDERER().setViewport(to_set.pos,
                               to_set.size);
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
        if (!root) {
            fprintf(file, "%s", "ROOT");
        } else {
            fprintf(file, "win%p", reinterpret_cast<void*>(root));
        }
        fprintf(file, " -> win%p\n", reinterpret_cast<void*>(child));
        dump(file, child);
    }
}

/*----------------------------------------------------------------------------*/

WindowManager::WindowNode& WindowManager::get(Window* window) {
    return Layout()[window];
}

/*============================================================================*/