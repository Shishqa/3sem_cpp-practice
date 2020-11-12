/*============================================================================*/
#ifndef SHISHGL_CURSOR_LOCATOR_HPP
#define SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/
#include "Window.hpp"
#include "Rectangle.hpp"
/*============================================================================*/
namespace ShishGL {

    class CursorLocator : public Window<Rectangle> {
    public:

        CursorLocator(Object::ID id, Object::ID parent);

    protected:

        bool onMouseMove(MouseEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/