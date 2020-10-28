/*============================================================================*/
#ifndef SFML_ENGINE_HPP
#define SFML_ENGINE_HPP
/*============================================================================*/
#include <cstddef>

#include <SFML/Graphics.hpp>

#include "ShishGL/utility/color.hpp"
#include "ShishGL/geometry/vector2.hpp"
#include "ShishGL/core/event.hpp"
/*============================================================================*/
namespace ShishGL {

    class SfmlEngine {
    protected:

        SfmlEngine() = default;

        /* Essential */
        /*--------------------------------------------------------------------*/
        static bool initialize(int* argc_ptr, char* argv[]);

        static bool terminate();

        static Vector2<size_t> getDisplaySize();
        /*--------------------------------------------------------------------*/

        /* ??? */
        static void clear();

        static void display();
        /* ??? */

        /* Events */
        /*--------------------------------------------------------------------*/
        static bool pollEvent(Event& event);
        /*--------------------------------------------------------------------*/

    public:

        /* Draw */
        /*--------------------------------------------------------------------*/
        static void setColor(const Color& color);

        static void fillBackground(const Color& color);

        static void drawRectangle(const Vector2<int>& pos,
                                  const Vector2<size_t>& size);
        /*--------------------------------------------------------------------*/

    private:

        /* Implementation special */
        /*====================================================================*/
        static sf::RenderWindow* canvas;

        static Color active_color;

    public:

        virtual ~SfmlEngine() = default;

    };

}
/*============================================================================*/
#endif //GLUT_ENGINE_HPP
/*============================================================================*/
