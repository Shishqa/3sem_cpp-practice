/*============================================================================*/
#ifndef SHISHGL_CURSOR_LOCATOR_HPP
#define SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/
#include "Core/GraphicsPlatform/Window/Window.hpp"
/*============================================================================*/
namespace ShishGL {

    class CursorLocator : public Window {
    public:

        CursorLocator(Object::ID id, Object::ID shape,
                      Object::ID parent = LayoutManager::ROOT);

    protected:

        bool onMouseMove(MouseEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/