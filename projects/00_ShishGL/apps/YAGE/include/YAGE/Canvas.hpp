/*============================================================================*/
#ifndef SHISHGL_CANVAS_HPP
#define SHISHGL_CANVAS_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Image.hpp"
#include "RenderSystem.hpp"
#include "ToolManager.hpp"
#include "Pen.hpp"
using namespace ShishGL;
/*============================================================================*/
namespace YAGE {

    class CanvasBehaviour;

    class Canvas : public UIButton {
    public:

        explicit Canvas(const Viewport& viewport);

    protected:

        void onRender() override;

    private:

        Image img;
        friend class CanvasBehaviour;

    };

    /*------------------------------------------------------------------------*/

    class CanvasBehaviour : public Clickable {
    public:

        explicit CanvasBehaviour(Window* target);

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseMove(MouseEvent& event) override;

    private:

        bool applying_tool;

    };

}
/*============================================================================*/
#endif //SHISHGL_CANVAS_HPP
/*============================================================================*/
