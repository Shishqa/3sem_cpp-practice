/*============================================================================*/
#ifndef SHISHGL_SFML_ENGINE_HPP
#define SHISHGL_SFML_ENGINE_HPP
/*============================================================================*/
#include <cstddef>

#include <SFML/Graphics.hpp>

#include "ShishGL/color/color.hpp"
#include "ShishGL/geometry/vector2.hpp"
#include "ShishGL/core/event/base_event.hpp"
/*============================================================================*/
namespace ShishGL {

    class SfmlEngine {
    public:

        /* Input */
        /*--------------------------------------------------------------------*/
        static Vector2<int> getMousePos();
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        static void setColor(const Color& color);

        static void drawRectangle(const Vector2<int>& pos,
                                  const Vector2<size_t>& size);

        static void drawCircle(const Vector2<int>& pos,
                               const size_t& radius);
        /*--------------------------------------------------------------------*/

        virtual ~SfmlEngine() = default;

    protected:

        /* Essential */
        /*--------------------------------------------------------------------*/
        static bool initDisplay(int* argc_ptr, char* argv[]);

        static bool isRunning();

        static bool closeDisplay();

        static Vector2<size_t> getDisplaySize();
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
        static void clear(const Color& color);

        static void render();
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
        static Event* pollEvent();
        /*--------------------------------------------------------------------*/

    private:

        SfmlEngine() = default;

        /* IMPLEMENTATION SPECIAL */
    /*========================================================================*/

        static bool is_running;

        static sf::RenderWindow* canvas;

        static Color active_color;

    };

}
/*============================================================================*/
#endif //SHISHGL_SFML_ENGINE_HPP
/*============================================================================*/
