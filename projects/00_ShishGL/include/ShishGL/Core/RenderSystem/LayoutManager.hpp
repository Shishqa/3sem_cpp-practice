/*============================================================================*/
#ifndef SHISHGL_LAYOUT_MANAGER_HPP
#define SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
#include <list>

#include "Object.hpp"
/*============================================================================*/
namespace ShishGL {

    class LayoutManager {
    public:

        using RenderLayout = std::list<Object::ID>;

        static void putOnTop(Object::ID id);

        static const RenderLayout& getLayout();

        virtual ~LayoutManager() = default;

    private:

        LayoutManager() = default;

        static RenderLayout& Layout();

    };

}
/*============================================================================*/
#endif //SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
