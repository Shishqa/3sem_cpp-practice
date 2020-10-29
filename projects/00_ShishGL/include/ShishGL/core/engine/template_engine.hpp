/*============================================================================*/
#ifndef SHISHGL_TEMPLATE_ENGINE_HPP
#define SHISHGL_TEMPLATE_ENGINE_HPP
/*============================================================================*/
namespace ShishGL {

    template <typename GraphicEngine>
    class TemplateEngine : public GraphicEngine {
    private:
        TemplateEngine() = default;

        /* giving roots for some classes */
        friend class EventSystem;
        friend class CoreApplication;

    public:
        virtual ~TemplateEngine() = default;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEMPLATE_ENGINE_HPP
/*============================================================================*/
