#ifndef EVENT_HPP
#define EVENT_HPP


#include <queue>
#include "graphic_interface.hpp"


namespace ShishGL {

    class Object;
    class WindowManager;


    struct Event {
    public:

        enum EventTypes {
            NONE,
            IDLE,
            MOUSE_BUTTON_PRESSED,
            MOUSE_BUTTON_RELEASED,
            MOUSE_ENTERED,
            MOUSE_LEFT,
            MOUSE_MOVED,
            KEY_PRESSED,
            KEY_RELEASED,
            RESIZED
        };

        virtual int type() = 0;

        virtual GI::WIN_ID object() = 0;
    };


    class EventSystem {
    public:

        ~EventSystem() = default;

        static void sendSignal(const Signal* signal);

    private:

        EventSystem()  = default;

        using EventQueue = std::queue<const GI::Event*>;

        static EventQueue& Events();

        static void processNewEvents();

        friend Object;
        friend WindowManager;
    };
}


#endif //EVENT_HPP
