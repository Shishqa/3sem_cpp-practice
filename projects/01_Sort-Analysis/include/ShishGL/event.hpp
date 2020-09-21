#ifndef EVENT_HPP
#define EVENT_HPP


#include <queue>


namespace ShishGL {

    class Object;


    struct Event {
        Object* target;
        int event_code;
    };


    class EventSystem {
    public:

        EventSystem() = default;
        ~EventSystem() = default;

        static void addEvent(const Event& event);

    private:

        static std::queue<Event> events;
        static void processNewEvents();

        friend Object;
    };

}


#endif //EVENT_HPP
