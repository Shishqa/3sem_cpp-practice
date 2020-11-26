/*============================================================================*/
#ifndef SHISHGL_ERASER_HPP
#define SHISHGL_ERASER_HPP
/*============================================================================*/
#include "Pen.hpp"
/*============================================================================*/
namespace YAGE {

    class Eraser : public Pen {
    public:

        Eraser() : Pen()
        { }

        void startApplying(Image& img, const Vector2<int64_t>& pos) override {
            last_pos = pos;
            draw(img, pos, StrokeProperties::activeThickness(), COLOR::NONE);
        }

        void update(Image& img, const Vector2<int64_t>& pos) override {
            draw(img, pos, StrokeProperties::activeThickness(), COLOR::NONE);
            last_pos = pos;
        }

        void stopApplying(Image& img, const Vector2<int64_t>& pos) override {
            update(img, pos);
        }

        [[nodiscard]]
        std::string_view getIcon() const override {
            return "./textures/tools/019-eraser.png";
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_ERASER_HPP
/*============================================================================*/
