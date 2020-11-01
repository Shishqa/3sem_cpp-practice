/*============================================================================*/
#ifndef SHISHGL_SCROLLABLE_HPP
#define SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
#include <cstddef>
/*============================================================================*/
namespace ShishGL {

    class Slidable {
    public:

        virtual void slide(double delta) = 0;

        virtual ~Slidable() = default;

    };

    /*------------------------------------------------------------------------*/

    class Scrollable : public Slidable {
    public:

        virtual double stepSize() = 0;

        void scroll(int n_steps) {
            slide(stepSize() * static_cast<double>(n_steps));
        }

        ~Scrollable() override = default;

    };

    /*------------------------------------------------------------------------*/

    class FrameScrollable : public Scrollable {
    public:

        virtual double frameSize() = 0;

        ~FrameScrollable() override = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
