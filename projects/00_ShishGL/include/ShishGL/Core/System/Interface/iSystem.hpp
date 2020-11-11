/*============================================================================*/
#ifndef SHISHGL_ISYSTEM_HPP
#define SHISHGL_ISYSTEM_HPP
/*============================================================================*/
#include <string_view>

#include "Vector2.hpp"
#include "Color.hpp"
/*============================================================================*/
namespace ShishGL {

    class ISystem {
    public:

        /* Input */
        /*--------------------------------------------------------------------*/
        virtual Vector2<double> getMousePos() = 0;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        virtual void setColor(const Color& color) = 0;

        virtual void drawPoint(const Vector2<double>& pos) = 0;

        virtual void drawLine(const Vector2<double>& start,
                             const Vector2<double>& end) = 0;

        virtual void drawRectangle(const Vector2<double>& pos,
                                  const Vector2<double>& size) = 0;

        virtual void drawCircle(const Vector2<double>& pos,
                               const size_t& radius) = 0;
        /*--------------------------------------------------------------------*/

        /* TODO: Text */
        /*--------------------------------------------------------------------*/
        virtual void displayText(const std::string_view& text,
                                 size_t font_size,
                                 const Vector2<double>& pos) = 0;
        /*--------------------------------------------------------------------*/

        virtual ~ISystem() = default;

    protected:

        friend class CoreApplication;

        ISystem() = default;

        /* Essential */
        /*--------------------------------------------------------------------*/
        virtual bool initDisplay(int* argc_ptr, char* argv[]) = 0;

        virtual bool isRunning() = 0;

        virtual bool closeDisplay() = 0;

        virtual Vector2<size_t> getDisplaySize() = 0;
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
        virtual void clear(const Color& color) = 0;

        virtual void display() = 0;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
        virtual bool pollEvent() = 0;
        /*--------------------------------------------------------------------*/

    };

}

/*============================================================================*/
#endif //SHISHGL_ISYSTEM_HPP
/*============================================================================*/
