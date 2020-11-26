/*============================================================================*/
#ifndef SHISHGL_PEN_HPP
#define SHISHGL_PEN_HPP
/*============================================================================*/
#include "ITool.hpp"
#include "ToolManager.hpp"
#include "StrokeProperties.hpp"
/*============================================================================*/
namespace YAGE {

    class Pen : public Tool {
    public:

        Pen() : last_pos({})
        { }

        void startApplying(Image& img, const Vector2<int64_t>& pos) override {
            last_pos = pos;
            draw(img, pos);
        }

        void update(Image& img, const Vector2<int64_t>& pos) override {
            draw(img, pos);
            last_pos = pos;
        }

        void stopApplying(Image& img, const Vector2<int64_t>& pos) override {
            update(img, pos);
        }

    private:

        static void draw(Image& img, const Vector2<int64_t>& pos) {

            int64_t thickness = StrokeProperties::activeThickness() / 2;

            int64_t x_l = pos.x - thickness;
            int64_t x_r = pos.x + thickness;
            int64_t y_u = pos.y - thickness;
            int64_t y_d = pos.y + thickness;

            for (int64_t x = x_l; x < x_r; ++x) {
                for (int64_t y = y_u; y < y_d; ++y) {
                    if (0 <= x && x < static_cast<int64_t>(img.size().x) &&
                        0 <= y && y < static_cast<int64_t>(img.size().y)) {
                        img.setPixel({static_cast<size_t>(x),
                                      static_cast<size_t>(y)},
                                     StrokeProperties::activeColor());
                    }
                }
            }
        }

        Vector2<int64_t> last_pos;

    };

}
/*============================================================================*/
#endif //SHISHGL_PEN_HPP
/*============================================================================*/
