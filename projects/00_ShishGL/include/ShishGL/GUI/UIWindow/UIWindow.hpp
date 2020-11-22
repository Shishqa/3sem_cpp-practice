/*============================================================================*/
#ifndef SHISHGL_SHAPED_WINDOW_HPP
#define SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/
namespace ShishGL {


    class Window : public PlatformListener {
    public:

        Window() = delete;

        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Shape2D& getShape() const;

        template <typename SomeShape, typename... Args>
        void applyShape(Args&&... args);

        void applyShape(Shape2D* new_shape);
        /*--------------------------------------------------------------------*/

        template <typename SomeStyle, typename... Args>
        void applyStyle(Args&&... args);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Viewport& getViewport() const;

        ~Window() override;

    protected:

        explicit Window(const Viewport& viewport);

        /*--------------------------------------------------------------------*/

        void fit_parent();

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        void setPos(const Vector2<double>& pos);

        void translate(const Vector2<double>& delta);

        /*--------------------------------------------------------------------*/

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const;

        /*--------------------------------------------------------------------*/

        virtual void onRender();

        virtual bool onMouseEntered(MouseEvent& event);

        virtual bool onMouseLeft(MouseEvent& event);

        bool onMouseMove(MouseEvent& event) override;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseScroll(MouseScrollEvent& event) override;

    private:

        template <typename SomeMouseEvent>
        bool resendMouse(SomeMouseEvent& event);

        bool is_active;

        Shape2D* shape;

        Viewport viewport;

        std::list<Style*> styles;

        friend class WindowManager;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPED_WINDOW_HPP
/*============================================================================*/