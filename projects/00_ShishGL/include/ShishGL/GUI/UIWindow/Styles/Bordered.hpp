/*============================================================================*/
#ifndef SHISHGL_BORDERED_HPP
#define SHISHGL_BORDERED_HPP
/*============================================================================*/
#include "GUI/UIWindow/Styles/Style.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class Bordered : public Style {
    public:

        explicit Bordered(const double& border_width,
                          const Color& border_color)
            : width(border_width)
            , color(border_color)
            { }

        void apply(Shape2D* shape) override {

            Vector2<double> old_dimension = shape->overallDimension();
            Vector2<double> offset{width, width};

            shape->translate(-offset);
            shape->setOverallDimension(old_dimension + 2.0 * offset);

            RENDERER().setColor(color);
            shape->draw();

            shape->translate(offset);
            shape->setOverallDimension(old_dimension);
        }

        ~Bordered() override = default;

    private:

        double width;
        Color color;


    };


}
/*============================================================================*/
#endif //SHISHGL_BORDERED_HPP
/*============================================================================*/
