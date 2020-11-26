/*============================================================================*/
#include "Slidable.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Slidable::Slidable(UIWindow* target, const Segment2<double>& slide, bool send_event)
        : Draggable(target)
        , need_reaction(send_event)
        , slide_seg(slide)
        { }

/*----------------------------------------------------------------------------*/

bool Slidable::onMouseMove(ShishGL::MouseEvent &event) {

    if (!Draggable::isHeld()) {
        return Draggable::onMouseMove(event);
    }

    Vector2<double> old_pos = target<UIWindow>()->getPos();
    Segment2<double> seg = slide_seg;

    auto parent = target<UIWindow>()->getParent();

    if (parent) {
        seg.begin += parent->getPos();
        seg.end   += parent->getPos();
    }

    Vector2<double> delta = event.where() - Draggable::dragPoint();

    Vector2<double> guide = seg.guide();
    Vector2<double> delta_proj = delta | guide;

    Vector2<double> new_pos = target<UIWindow>()->getPos() + delta_proj;

    if (((new_pos - seg.begin) ^ guide) < 0) {

        new_pos = seg.begin;

    } else if (((new_pos - seg.end) ^ guide) > 0) {

        new_pos = seg.end;

    }

    Vector2<double> correction =
            new_pos - target<UIWindow>()->getPos() - delta;

    Vector2<double> old_event_where = event.where();
    event.setWhere(event.where() + correction);

    bool status = Draggable::onMouseMove(event);

    event.setWhere(old_event_where);

    if (need_reaction) {
        EventSystem::sendEvent<SlideEvent>(this, new_pos - old_pos);
    }

    return status;
}

/*============================================================================*/