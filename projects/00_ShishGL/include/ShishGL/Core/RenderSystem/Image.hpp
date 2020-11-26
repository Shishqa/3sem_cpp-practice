/*============================================================================*/
#ifndef SHISHGL_IMAGE_HPP
#define SHISHGL_IMAGE_HPP
/*============================================================================*/
#include <cstddef>
#include <vector>
#include <memory>

#include "Color.hpp"
#include "ColorCollection.hpp"
#include "Vector2.hpp"
#include "IPlatform.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class Image {
    public:

        using Pixels = std::vector<Color>;

        explicit Image(const Vector2<size_t>& size,
                       const Color& color = COLOR::WHITE)
                : context(nullptr)
                , img_size(size) {

            pixels = reinterpret_cast<Color*>(aligned_alloc(sizeof(Color), size.x * size.y * sizeof(Color)));

            context = RENDERER().createContext(size, color);
        }

        void setPixel(const Vector2<size_t>& pos, const Color& color) {
            pixels[pos.y * img_size.x + pos.x] = color;
        }

        [[nodiscard]]
        const Vector2<size_t>& size() const {
            return img_size;
        }

        void draw(const Vector2<double>& pos) {
            context->update(pixels);
            RENDERER().displayContext(context, pos);
        }

        ~Image() {
            delete context;
            delete[] pixels;
        }

    private:

        IPlatform::IContext* context;

        Vector2<size_t> img_size;
        Color* pixels;

    };

}
/*============================================================================*/
#endif //SHISHGL_IMAGE_HPP
/*============================================================================*/