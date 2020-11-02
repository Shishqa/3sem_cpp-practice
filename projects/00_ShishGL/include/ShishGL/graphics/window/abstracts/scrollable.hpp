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

    class LimitSlidable : public Slidable {
    public:

        [[nodiscard]]
        virtual double limitSize() const = 0;

        ~LimitSlidable() override = default;

    };

    /*------------------------------------------------------------------------*/

    class Scrollable : public LimitSlidable {
    public:

        [[nodiscard]]
        virtual double stepSize() const = 0;

        void scroll(int n_steps) {
            slide(stepSize() * static_cast<double>(n_steps));
        }

        ~Scrollable() override = default;

    };

    /*------------------------------------------------------------------------*/

    class FrameScrollable : public Scrollable {
    public:

        [[nodiscard]]
        virtual double frameSize() const = 0;

        ~FrameScrollable() override = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
