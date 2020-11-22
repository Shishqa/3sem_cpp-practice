/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_IPP
#define SHISHGL_UI_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename SomeShape>
    UIWindow<SomeShape>::UIWindow(const Viewport& viewport)
        : Window(viewport)
        { }

    /*------------------------------------------------------------------------*/

    template <typename SomeShape>
    template <typename SomeStyle, typename... Args>
    void UIWindow<SomeShape>::applyStyle(Args&&... args) {
        auto* style = new SomeStyle(std::forward<Args>(args)...);
        styles.push_back(style);
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeShape>
    UIWindow<SomeShape>::~UIWindow() {
        for (auto& style : styles) {
            delete style;
        }
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeShape>
    void UIWindow<SomeShape>::onRender() {

        Shape shape;
        Viewport frame = getViewport();

        for (auto& style : styles) {
            style->apply(frame, shape);
        }

        shape.draw(frame);
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeShape>
    bool UIWindow<SomeShape>::contains(const Vector2<double>& point) const {
        Shape shape;
        return shape.contains(getViewport(), point);
    }

}
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_IPP
/*============================================================================*/
