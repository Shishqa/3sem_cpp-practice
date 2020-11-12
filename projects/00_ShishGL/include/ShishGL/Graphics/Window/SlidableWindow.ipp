/*============================================================================*/
#ifndef SHISHGL_SLIDABLE_WINDOW_IPP
#define SHISHGL_SLIDABLE_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    template <typename... Args>
    SlidableWindow<Shape>::SlidableWindow(Object::ID id, Object::ID parent,
                                          const Segment2<double> &slide,
                                          Args&&... args)
            : DraggableWindow<Shape>(id, parent, std::forward<Args>(args)...)
            , slide_seg(slide)
            { }

    /*------------------------------------------------------------------------*/

    template <typename Shape>
    bool SlidableWindow<Shape>::onMouseMove(ShishGL::MouseEvent& event) {

        if (!DraggableWindow<Shape>::isHolded()) {
            return HoldableWindow<Shape>::onMouseMove(event);
        }

        Vector2<double> delta = event.where() - DraggableWindow<Shape>::dragPoint();

        Vector2<double> guide = slide_seg.guide();
        Vector2<double> delta_proj = delta | guide;

        Vector2<double> new_pos = Window<Shape>::getShape().getPos() + delta_proj;

        if (((new_pos - slide_seg.begin) ^ guide) < 0) {

            new_pos = slide_seg.begin;

        } else if (((new_pos - slide_seg.end) ^ guide) > 0) {

            new_pos = slide_seg.end;

        }

        Vector2<double> correction =
                new_pos - Window<Shape>::getShape().getPos() - delta;

        event.setWhere(event.where() + correction);

        return (DraggableWindow<Shape>::onMouseMove(event));
    }

}
/*============================================================================*/
#endif //SHISHGL_SLIDABLE_WINDOW_IPP
/*============================================================================*/