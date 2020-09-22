#ifndef EVENT_HPP
#define EVENT_HPP


#include <queue>


namespace ShishGL {

    class Object;
    class Window;


    struct Event {
        Object* target;
        int event_code;
    };


    class EventSystem {
    public:

        EventSystem()  = default;
        ~EventSystem() = default;

        static void addEvent(const Event& event);

    private:

        typedef std::queue<Event> EventQueue;

        static EventQueue& Events();
        static void processNewEvents();

        friend Object;
        friend Window;
    };
}


#endif //EVENT_HPP
