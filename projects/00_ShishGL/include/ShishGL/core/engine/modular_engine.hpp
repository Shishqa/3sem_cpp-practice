/*============================================================================*/
#ifndef SHISHGL_TEMPLATE_ENGINE_HPP
#define SHISHGL_TEMPLATE_ENGINE_HPP
/*============================================================================*/
namespace ShishGL {

    template <typename GraphicEngine>
    class ModularEngine : public GraphicEngine {
    private:
        ModularEngine() = default;

        /* giving roots for some classes */
        friend class EventSystem;
        friend class CoreApplication;

    public:
        virtual ~ModularEngine() = default;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEMPLATE_ENGINE_HPP
/*============================================================================*/
