/*============================================================================*/
#ifndef SHISHGL_PEN_HPP
#define SHISHGL_PEN_HPP
/*============================================================================*/
#include "Tool.hpp"
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
            draw(img, pos, StrokeProperties::activeThickness(), StrokeProperties::activeColor());
        }

        void update(Image& img, const Vector2<int64_t>& pos) override {
            draw(img, pos, StrokeProperties::activeThickness(), StrokeProperties::activeColor());
            last_pos = pos;
        }

        void stopApplying(Image& img, const Vector2<int64_t>& pos) override {
            update(img, pos);
        }

        [[nodiscard]]
        std::string_view getIcon() const override {
            return "./textures/tools/011-pencil.png";
        }

    protected:

        static void draw(Image& img, const Vector2<int64_t>& pos,
                         size_t thickness, const Color& color);

        Vector2<int64_t> last_pos;

    };

}
/*============================================================================*/
#endif //SHISHGL_PEN_HPP
/*============================================================================*/
