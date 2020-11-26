/*============================================================================*/
#include "Canvas.hpp"
#include "ImageManager.hpp"
#include "Pen.hpp"
/*============================================================================*/
using namespace YAGE;
/*============================================================================*/

Canvas::Canvas(const Viewport& viewport)
        : UIWindow(viewport) {
    addBehavior<CanvasBehaviour>();
}

/*----------------------------------------------------------------------------*/

void Canvas::onRender() {
    ImageManager::displayImage(getPos());
}

/*============================================================================*/

CanvasBehaviour::CanvasBehaviour(UIWindow* target)
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
        ToolManager::activeTool().startApplying(ImageManager::getActiveLayer(),
                                                static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));

    } else if (event.state() == Mouse::UP &&
               event.button() == Mouse::LEFT) {
        applying_tool = false;
        ToolManager::activeTool().stopApplying(ImageManager::getActiveLayer(),
                                               static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool CanvasBehaviour::onMouseMove(MouseEvent& event) {
     if (applying_tool) {
         ToolManager::activeTool().update(ImageManager::getActiveLayer(),
                                          static_cast<Vector2<int64_t>>(event.where() - target<Window>()->getPos()));
         return true;
     }

     return false;
}

/*============================================================================*/
