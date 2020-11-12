/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <type_traits>
#include <unordered_set>

#include "SystemObject.hpp"
#include "MouseEvent.hpp"
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    class Window : public SystemObject {
    private:

        /*--------------------------------------------------------------------*/
        template <typename SomeWindow, typename T>
        using WindowHelper =
                std::enable_if_t<std::is_base_of<Window, SomeWindow>::value, T>;

        template <typename SomeShape, typename T>
        using ShapeHelper =
                std::enable_if_t<std::is_base_of<Shape2D, SomeShape>::value, T>;
        /*--------------------------------------------------------------------*/

    public:

        /*--------------------------------------------------------------------*/
        template <typename... Args>
        explicit Window(Object::ID id, Object::ID parent, Args&&... args);

        Window() = delete;

        ~Window() override;
        /*--------------------------------------------------------------------*/

        /*--------------------------------------------------------------------*/
        template <typename SomeWindow, typename... Args>
        Object::ID attach(Args&&... args);

        bool detach(Object::ID subwindow);
        /*--------------------------------------------------------------------*/

    protected:

        virtual bool onMouseEntered(MouseEvent&);

        virtual bool onMouseLeft(MouseEvent&);

        bool onMouseMove(MouseEvent& event) override;

        Shape& getShape() const;

    private:

        bool is_active;

        Shape2D::ID shape;

        using WindowPool = std::unordered_set<Window::ID>;

        Window::ID parent;
        WindowPool subwindows;

    };

}
/*============================================================================*/
#include "Window.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
