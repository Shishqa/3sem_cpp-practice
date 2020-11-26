/*============================================================================*/
#ifndef SHISHGL_IMAGE_MANAGER_HPP
#define SHISHGL_IMAGE_MANAGER_HPP
/*============================================================================*/
#include <string_view>
#include <vector>

#include "Vector2.hpp"
#include "Color.hpp"
#include "ColorCollection.hpp"
#include "Image.hpp"
using namespace ShishGL;
/*============================================================================*/
namespace YAGE {

    class ImageManager {
    public:

        /*
         * TODO:
         * 1) add layers
         * 2) active layer
         * 3) layer selector
         *
         */

        ImageManager() = delete;

        static void loadImage(const std::string_view& filename) {
            delete ImageContext();
            ImageContext() = RENDERER().loadContextFromImage(filename);
        }

        static void saveImage(const std::string_view& filename) {
            RENDERER().saveContextAsImage(ImageContext(), filename);
        }

        static Image& getActiveLayer() {
            return Layers()[ActiveLayer()];
        };

        static void createImage(const Vector2<size_t>& size) {

            delete ImageContext();
            ImageContext() = RENDERER().createContext(size, COLOR::WHITE);

            Layers().clear();
            Layers().emplace_back(size, COLOR::WHITE);
            Layers().emplace_back(size, COLOR::NONE);
            ActiveLayer() = 1;
        }

        static void displayImage(const Vector2<double>& pos) {

            Image result(Layers()[0].size());

            for (auto& layer : Layers()) {
                result.blend(layer);
            }

            ImageContext()->update(result.getPixels());

            RENDERER().displayContext(ImageContext(), pos);
        }

    private:

        using LayerPool = std::vector<Image>;

        static size_t& ActiveLayer() {
            static size_t ACTIVTE_LAYER = 0;
            return ACTIVTE_LAYER;
        }

        static LayerPool& Layers() {
            static LayerPool LAYERS;
            return LAYERS;
        }

        static IPlatform::IContext*& ImageContext() {
            static IPlatform::IContext* CONTEXT = nullptr;
            return CONTEXT;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_IMAGE_MANAGER_HPP
/*============================================================================*/
