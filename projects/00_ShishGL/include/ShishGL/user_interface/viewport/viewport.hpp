/*============================================================================*/
#ifndef SHISHGL_VIEWPORT_HPP
#define SHISHGL_VIEWPORT_HPP
/*============================================================================*/
#include "ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    class Viewport : public RectWindow {
    protected:

        static constexpr size_t SCROLLBAR_WIDTH = 20;

    public:

        Viewport(Window* parent,
                 const Vector2<double>& pos,
                 const Vector2<double>& size);

    protected:

        void onRender() override;

    };

}
/*============================================================================*/
#endif //SHISHGL_VIEWPORT_HPP
/*============================================================================*/
