/*============================================================================*/
#ifndef SHISHGL_ISYSTEM_HPP
#define SHISHGL_ISYSTEM_HPP
/*============================================================================*/
namespace ShishGL {

    class ISystem {
    public:

        /* Input */
        /*--------------------------------------------------------------------*/
        static Vector2<double> getMousePos();
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        static void setColor(const Color& color);

        static void drawPoint(const Vector2<double>& pos);

        static void drawLine(const Vector2<double>& start,
                             const Vector2<double>& end);

        static void drawRectangle(const Vector2<double>& pos,
                                  const Vector2<double>& size);

        static void drawCircle(const Vector2<double>& pos,
                               const size_t& radius);
        /*--------------------------------------------------------------------*/

        /* TODO: Text */
        /*--------------------------------------------------------------------*/
        static void displayText(const std::string_view& text, size_t font_size,
                                const Vector2<double>& pos);
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

        static sf::Font& ActiveFont();

    };

}

/*============================================================================*/
#endif //SHISHGL_IPLATFORM_HPP
/*============================================================================*/
