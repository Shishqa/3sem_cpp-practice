/*============================================================================*/
#ifndef SHISHGL_SFML_PLATFORM_HPP
#define SHISHGL_SFML_PLATFORM_HPP
/*============================================================================*/
#include <cstddef>
#include <string_view>

#include <SFML/Graphics.hpp>

#include "IPlatform.hpp"
/*============================================================================*/
namespace ShishGL {

    class SfmlPlatform : public IPlatform {
    public:

        SfmlPlatform();

        bool isRunning() override;

        /* Input */
        /*--------------------------------------------------------------------*/
        Vector2<double> getMousePos() override;
        /*--------------------------------------------------------------------*/

        /* View */
        /*--------------------------------------------------------------------*/
        void setViewport(const Vector2<double>& pos,
                         const Vector2<double>& size,
                         const Vector2<double>& dp_pos,
                         const Vector2<double>& dp_size) override;

        const Vector2<double>& getDisplaySize() override;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        void setColor(const Color& color) override;

        void drawPoint(const Vector2<double>& pos) override;

        void drawLine(const Vector2<double>& start,
                      const Vector2<double>& end) override;

        void drawRectangle(const Vector2<double>& pos,
                           const Vector2<double>& size) override;

        void drawCircle(const Vector2<double>& pos,
                        const double& radius) override;
        /*--------------------------------------------------------------------*/

        /* Image */
        /*--------------------------------------------------------------------*/
        void displayImage(const uint8_t* data, const size_t& data_size,
                          const Vector2<double>& pos) override;

        /* Text */
        /*--------------------------------------------------------------------*/
        void displayText(const std::string_view& text, size_t font_size,
                         const Vector2<double>& pos) override;
        /*--------------------------------------------------------------------*/


        ~SfmlPlatform() override = default;

    protected:

        /* Essential */
        /*--------------------------------------------------------------------*/
         bool initDisplay(int* argc_ptr, char* argv[]) override;

         bool closeDisplay() override;
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
         void clear(const Color& color) override;

         void display() override;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
         bool pollEvent() override;
        /*--------------------------------------------------------------------*/

    private:

        /* IMPLEMENTATION SPECIAL */
        /*====================================================================*/

        Vector2<double> display_size;

        bool is_running;

        sf::RenderWindow* canvas;

        Color active_color;

        sf::Font active_font;

    };

}
/*============================================================================*/
#endif //SHISHGL_SFML_PLATFORM_HPP
/*============================================================================*/
