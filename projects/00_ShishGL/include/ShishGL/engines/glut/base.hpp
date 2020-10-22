/*============================================================================*/
#ifndef GLUT_ENGINE_HPP
#define GLUT_ENGINE_HPP
/*============================================================================*/
#include <string_view>
#include <cstddef>

#include "ShishGL/utility/color.hpp"
#include "ShishGL/geometry/vector2.hpp"
/*============================================================================*/
namespace ShishGL {

    class GlutEngine {
    protected:

        /* Essential */
        /*--------------------------------------------------------------------*/
        static void initialize(int* argc_ptr, char* argv[]);

        static void terminate();

        static uint8_t enterMainLoop();

        static size_t getDisplayWidth();

        static size_t getDisplayHeight();
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        static void setColor(const Color& color);

        static void fillWithColor(const Color& color);

        static void drawRectangle(const Vector2<int>& pos,
                                  const Vector2<size_t>& size);
        /*--------------------------------------------------------------------*/

        /* Implementation details */
        /*--------------------------------------------------------------------*/
        static int canvas_id;

        static void setInitOptions();

        static void setHandlers();
        /*--------------------------------------------------------------------*/

        /* Low-level event handlers */
        /*--------------------------------------------------------------------*/
        static void manageRender();

        static void manageKey(unsigned char key, int x, int y);

        static void manageMouse(int button, int state, int x, int y);

        static void manageMotion(int x, int y);

        static void managePassiveMotion(int x, int y);
        /*--------------------------------------------------------------------*/

        GlutEngine() = default;

    public:

        virtual ~GlutEngine() = default;

    };

}
/*============================================================================*/
#endif //GLUT_ENGINE_HPP
/*============================================================================*/
