/*============================================================================*/
#include "Window.hpp"
#include "Object.hpp"
#include "WindowManager.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/
//
//Window::Window(Object::ID id, Object::ID win_shape)
//        : Renderable(id)
//        , PlatformListener()
//        , is_active(false)
//        , viewport({})
//        , shape(win_shape) {
//
//    printf("PARENT\n");
//    fflush(stdout);
//
//    auto& shape_ref = GET<Shape2D>(shape);
//
//    viewport = Viewport{
//            shape_ref.getPos(),
//            shape_ref.overallDimension()
//    };
//
//    LayoutManager::putRoot(Renderable::id());
//    LayoutManager::attach(Renderable::id(), shape);
//
//    SubscriptionManager::subscribe(EventSystem::SystemEvents, this);
//}

/*------------------------------------------------------------------------*/

Window::Window(Object::ID id, Object::ID shape, Object::ID parent)
        : Renderable(id)
        , PlatformListener()
        , viewport({})
        , use_viewport(false)
        , is_active(false)
        , shape(shape) {

    printf("WINDOW, parent = %lu\n", parent);
    fflush(stdout);

    auto& shape_ref = GET<Shape2D>(shape);

    if (parent != LayoutManager::ROOT) {

        auto &parent_ref = GET<Window>(parent);
        shape_ref.translate(parent_ref.getViewport().pos);

        SubscriptionManager::subscribe(&parent_ref, this);
    }

    viewport = Viewport{
            shape_ref.getPos(),
            shape_ref.overallDimension()
    };

    LayoutManager::attach(parent, Object::id());
    LayoutManager::attach(Object::id(), shape_ref.id());

    if (parent == LayoutManager::ROOT) {
        SubscriptionManager::subscribe(EventSystem::SystemEvents, this);
    }
}

/*----------------------------------------------------------------------------*/

bool Window::detach(Object::ID) {
    /* TODO */
    return true;
}

/*----------------------------------------------------------------------------*/

void Window::setViewportUse(bool state) {
    use_viewport = state;
}

/*----------------------------------------------------------------------------*/

bool Window::onRender() {

    if (!use_viewport) {
        return true;
    }

    Viewport to_set = viewport;

    Object::ID parent = LayoutManager::getParent(id());

    if (LayoutManager::ROOT != parent) {

        Viewport parent_vp = GET<Window>(parent).getViewport();

        to_set.size.x = std::min(to_set.size.x, parent_vp.pos.x +
                                 parent_vp.size.x - to_set.pos.x);

        to_set.size.y = std::min(to_set.size.y, parent_vp.pos.y +
                                 parent_vp.size.y - to_set.pos.y);

        if (to_set.pos.x < parent_vp.pos.x) {
            to_set.size.x -= (parent_vp.pos.x - to_set.pos.x);
            to_set.pos.x = parent_vp.pos.x;
        }

        if (to_set.pos.y < parent_vp.pos.y) {
            to_set.size.y -= (parent_vp.pos.y - to_set.pos.y);
            to_set.pos.y = parent_vp.pos.y;
        }

    }

    RENDERER().setViewport(to_set.pos, to_set.size);

    return true;
}

/*------------------------------------------------------------------------*/

bool Window::onMouseEntered(MouseEvent&) { return false; }

bool Window::onMouseLeft(MouseEvent &) { return false; }

/*------------------------------------------------------------------------*/

bool Window::onMouseMove(MouseEvent& event) {

    bool is_event_inside = getShape().contains(event.where());

    bool status = false;

    if (is_active && !is_event_inside) {

        is_active = false;

        if (onMouseLeft(event)) {
            status = true;
        }

    } else if (!is_active && is_event_inside) {

        is_active = true;
        if (onMouseEntered(event)) {
            status = true;
        }
    }

    Vector2<double> where = event.where();
    event.setWhere(getViewport().pos - viewport.pos + where);

    if (EventSystem::sendEvent(this, event)) {
        status = true;
    }

    event.setWhere(where);

    return status;
}

/*------------------------------------------------------------------------*/

bool Window::onMouseButton(MouseButtonEvent& event) {

    Vector2<double> where = event.where();
    event.setWhere(where + getViewport().pos);

    bool status = EventSystem::sendEvent(this, event);

    event.setWhere(where);

    return status;
}

bool Window::onMouseScroll(class MouseScrollEvent& event) {

    Vector2<double> where = event.where();
    event.setWhere(where + getViewport().pos);

    bool status = EventSystem::sendEvent(this, event);

    event.setWhere(where);

    return status;
}

/*------------------------------------------------------------------------*/

Shape2D& Window::getShape() const {
    return GET<Shape2D>(shape);
}

/*------------------------------------------------------------------------*/

const Viewport& Window::getViewport() const {
    return viewport;
}

/*============================================================================*/