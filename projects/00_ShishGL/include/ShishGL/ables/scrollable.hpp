/*============================================================================*/
#ifndef SHISHGL_SCROLLABLE_HPP
#define SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
#include <cstddef>
/*============================================================================*/
namespace ShishGL {

    class Slidable {
    public:

        virtual void slide(int delta) = 0;

        virtual ~Slidable() = default;

    };

    /*------------------------------------------------------------------------*/

    class Scrollable : public Slidable {
    public:

        virtual size_t stepSize() = 0;

        void scroll(int n_steps) {
            slide(static_cast<int>(stepSize()) * n_steps);
        }

        ~Scrollable() override = default;

    };

    /*------------------------------------------------------------------------*/

    class FrameScrollable : public Scrollable {
    public:

        virtual size_t getFrameSize() = 0;

        virtual size_t getContentSize() = 0;

        double getProportion() {
            return static_cast<double>(getFrameSize()) /
                   static_cast<double>(getContentSize());
        }

        ~FrameScrollable() override = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SCROLLABLE_HPP
/*============================================================================*/
