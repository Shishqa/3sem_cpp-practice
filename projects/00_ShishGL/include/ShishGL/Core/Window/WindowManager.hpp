/*============================================================================*/
#ifndef SHISHGL_LAYOUT_MANAGER_HPP
#define SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
#include <list>
#include <unordered_map>
#include <string_view>

#include "Window.hpp"
/*============================================================================*/
namespace ShishGL {

    class WindowManager {

        struct Node {
            std::list<Window*> children;
            Window* parent;
        };

    public:

        template <typename SomeWindow>
        static SomeWindow* create(Vector2<double>);

        using RenderLayout = std::unordered_map<Window*, Node>;

        static constexpr Window* ROOT = nullptr;

        static Window* getParent(Window* window);

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
