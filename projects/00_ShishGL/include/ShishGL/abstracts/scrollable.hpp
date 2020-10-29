/*============================================================================*/
#ifndef SHISHGL_SCROLLABLE_HPP
#define SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
namespace ShishGL {

    class Scrollable {
    public:

        virtual void scroll(double ratio) = 0;

        virtual double getProportion() = 0;

        virtual ~Scrollable() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
