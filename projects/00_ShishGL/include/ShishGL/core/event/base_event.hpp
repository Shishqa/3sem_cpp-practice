/*============================================================================*/
#ifndef SHISHGL_BASE_EVENT_HPP
#define SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
#include <cstdint>

#include "ShishGL/core/object.hpp"
/*============================================================================*/
namespace ShishGL {

    class Event {
    public:

        enum Type {
            NONE = 0,
            RENDER,
            MOUSE_BUTTON,
            MOUSE_SCROLL,
            MOUSE_MOVE,
            KBD_BUTTON,
            TIMER,
            IDLE,
            SLIDE,

            USER_MIN = 100,
            /* USER TYPES */
            USER_MAX = 255
        };

        explicit Event(Event::Type type)
            : e_type(type) {}

        [[nodiscard]]
        inline Type type() const { return static_cast<Type>(e_type); }

        virtual bool happen(Object* object) const {
            return object->unhandledEvent(this);
        }

        virtual ~Event() = default;

    protected:

        uint8_t e_type;

    };

    /*------------------------------------------------------------------------*/

    class RenderEvent : public Event {
    public:

        explicit RenderEvent(Event::Type type = Event::RENDER)
            : Event(type) {}

        ~RenderEvent() override = default;

        bool happen(Object* object) const override {
            object->onRender(this);
        }

    };

    /*------------------------------------------------------------------------*/

    class SlideEvent : public Event {
    public:

        SlideEvent(Event::Type type, double delta)
            : Event(type)
            , e_delta(delta) {}

        ~SlideEvent() override = default;

        [[nodiscard]]
        inline double delta() const { return e_delta; }

    protected:

        double e_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_BASE_EVENT_HPP
/*============================================================================*/
