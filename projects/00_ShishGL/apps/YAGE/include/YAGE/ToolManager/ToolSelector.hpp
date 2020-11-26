/*============================================================================*/
#ifndef SHISHGL_TOOL_SELECTOR_HPP
#define SHISHGL_TOOL_SELECTOR_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
#include "ToolManager.hpp"
using namespace ShishGL;
/*============================================================================*/
namespace YAGE {

    class ToolButtonBehaviour : public Clickable {
    public:

        explicit ToolButtonBehaviour(Window* target,
                                     const Tool* tool)
            : Clickable(target)
            , impl_to_set(tool)
            { }

    protected:

        void reactOnRelease(MouseButtonEvent&) override {
            EventSystem::sendEvent<ToolSelectEvent>(this, impl_to_set);
        }

    private:

        const Tool* impl_to_set;

    };

    /*------------------------------------------------------------------------*/

    class ToolSelectorButton : public UIButton {



    };

}
/*============================================================================*/
#endif //SHISHGL_TOOL_SELECTOR_HPP
/*============================================================================*/
