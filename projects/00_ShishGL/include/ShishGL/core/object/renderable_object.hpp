/*============================================================================*/
#ifndef SHISHGL_RENDERABLE_OBJECT_HPP
#define SHISHGL_RENDERABLE_OBJECT_HPP
/*============================================================================*/
#include <unordered_set>

#include "ShishGL/core/geometry/vector2.hpp"
#include "object.hpp"
/*============================================================================*/
namespace ShishGL {

    class RenderableObject : public Object {
    protected:

        Vector2<double> abs_pos;

    public:

        ~RenderableObject() override {
            for (auto& obj : nested_objects) {
                delete obj;
            }
        }

        virtual bool onRender() = 0;

        void refresh() { this->onRender(); }

        /*--------------------------------------------------------------------*/
        [[nodiscard]]
        virtual Vector2<double> getAbsPos() const = 0;

        [[nodiscard]]
        Vector2<double> getRelPos() const {
            if (parent) {
                return getAbsPos() - parent->getAbsPos();
            }
            return getAbsPos();
        }

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const = 0;

        /*--------------------------------------------------------------------*/
        template <typename SomeRenderable, typename... Args>
        SomeRenderable* attach(Args&&... args) {

            /* TODO: sfinae! */
            if (!std::is_base_of<RenderableObject, SomeRenderable>::value) {
                return nullptr;
            }

            auto win_ptr = new SomeRenderable(this, std::forward<Args>(args)...);

            nested_objects.insert(win_ptr);
            return win_ptr;
        }

        RenderableObject* detach(RenderableObject* obj_ptr) {
            return (nested_objects.erase(obj_ptr) ? nullptr : obj_ptr);
        }
        /*--------------------------------------------------------------------*/

    protected:

        using ObjectSet = std::unordered_set<RenderableObject*>;

        ObjectSet nested_objects;
        RenderableObject* parent;

    };

}
/*============================================================================*/
#endif //SHISHGL_RENDERABLE_OBJECT_HPP
/*============================================================================*/
