/*============================================================================*/
#include "Canvas.hpp"
/*============================================================================*/
using namespace YAGE;
/*============================================================================*/

Canvas::Canvas(const Viewport& viewport)
        : UIButton(viewport)
        , img(static_cast<Vector2<size_t>>(viewport.size), COLOR::CYAN) {
        setBehaviour<CanvasBehaviour>();
}

/*----------------------------------------------------------------------------*/

void Canvas::onRender() {
    img.draw(getPos());
}

/*============================================================================*/

CanvasBehaviour::CanvasBehaviour(Window* target)
        : Clickable(target)
        , applying_tool(false) {
    SubscriptionManager::subscribe(EventSystem::SystemEvents, this,
                                       MOUSE_MOVE | MOUSE_BUTTON);
    ToolManager::set<Pen>();
}

/*----------------------------------------------------------------------------*/

bool CanvasBehaviour::onMouseButton(MouseButtonEvent& event) {

    if (!Clickable::onMouseButton(event)) {
        return false;
    }

    if (event.state() == Mouse::DOWN &&
        event.button() == Mouse::LEFT) {

        applying_tool = true;
        ToolManager::activeTool().startApplying(target<Canvas>()->img,
                                                static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));

    } else if (event.state() == Mouse::UP &&
               event.button() == Mouse::LEFT) {
        applying_tool = false;
        ToolManager::activeTool().stopApplying(target<Canvas>()->img,
                                               static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool CanvasBehaviour::onMouseMove(MouseEvent& event) {
     if (applying_tool) {
         ToolManager::activeTool().update(target<Canvas>()->img,
                                          static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));
         return true;
     }

     return false;
}

/*============================================================================*/
