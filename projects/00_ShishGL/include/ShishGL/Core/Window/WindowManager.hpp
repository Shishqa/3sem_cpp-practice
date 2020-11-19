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
    private:

        struct Node {
            std::list<Window*> children;
            Window* parent;
        };

    public:

        WindowManager() = delete;

        using RenderLayout = std::unordered_map<Window*, Node>;

        template <typename SomeWindow, typename SomeShape, typename... Args>
        static SomeWindow* create(Args&&... args);

        static constexpr Window* ROOT = nullptr;

        static Window* getParent(Window* window);

        static void putRoot(Window* window);

        static void attach(Window* parent, Window* child);

        static void detach(Window* child);

        static const RenderLayout& getLayout();

        static void dump(const std::string_view& file_name);

        virtual ~WindowManager() = default;

    private:

        static void refresh();

        static void refresh(Window* root);

        static void clear();

        static void clear(Window* root);

        static void dump(FILE* file, Window* root);

        static RenderLayout& Layout();

        friend class CoreApplication;

    };

}
/*============================================================================*/
#include "WindowManager.ipp"
/*============================================================================*/
#endif //SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
