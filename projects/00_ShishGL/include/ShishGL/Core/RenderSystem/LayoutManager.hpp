/*============================================================================*/
#ifndef SHISHGL_LAYOUT_MANAGER_HPP
#define SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
#include <list>
#include <unordered_map>
#include <string_view>

#include "Renderable.hpp"
/*============================================================================*/
namespace ShishGL {

    class LayoutManager {

        struct Node {
            std::list<Renderable::ID> children;
            Renderable::ID parent;
        };

    public:

        using RenderLayout = std::unordered_map<Renderable::ID, Node>;

        static constexpr Object::ID ROOT = 0;

        static Renderable::ID getParent(Renderable::ID obj);

        static void putRoot(Renderable::ID obj);

        static void attach(Renderable::ID parent, Renderable::ID child);

        static void detach(Renderable::ID parent, Renderable::ID child);

        static const RenderLayout& getLayout();

        static void dump(const std::string_view& file_name);

        virtual ~LayoutManager() = default;

    private:

        static void dump(FILE* file, Renderable::ID root);

        friend class RenderSystem;

        LayoutManager() = default;

        static RenderLayout& Layout();

    };

}
/*============================================================================*/
#endif //SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
