/*============================================================================*/
#ifndef SHISHGL_TEXTURE_FILL_HPP
#define SHISHGL_TEXTURE_FILL_HPP
/*============================================================================*/
#include <string_view>

#include "GUI/UIWindow/Styles/Style.hpp"
#include "Shape2D.hpp"
#include "ResourceManager.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class TextureFill : public Style {
    public:

        explicit TextureFill(const std::string_view& filename)
                : file(filename) {
            ResourceManager::load(file);
        }

        void apply(Shape2D*) override {
            RENDERER().setTexture(ResourceManager::get(file));
        }

        ~TextureFill() override = default;

    private:

        const std::string_view file;

    };

}
/*============================================================================*/
#endif //SHISHGL_TEXTURE_FILL_HPP
/*============================================================================*/
