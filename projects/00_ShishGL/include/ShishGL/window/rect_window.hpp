/*============================================================================*/
#ifndef SHISHGL_RECT_WINDOW_HPP
#define SHISHGL_RECT_WINDOW_HPP
/*============================================================================*/
#include "ShishGL/core/window_container.hpp"
#include "ShishGL/utility/color_collection.hpp"
/*============================================================================*/
namespace ShishGL {

    class RectWindow : public Window {
    protected:

        Vector2<size_t> size;
        Color color = BLACK;

    public:

        RectWindow(Window* parent,
                   const Vector2<int>& pos,
                   const Vector2<size_t>& size,
                   const Color& color);

        ~RectWindow() override = default;

    protected:

        bool getEvent(const Event* event) override;

        void onRender() override;

        bool contains(const Vector2<int>& point) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_RECT_WINDOW_HPP
/*============================================================================*/
