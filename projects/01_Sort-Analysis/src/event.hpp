#ifndef EVENT_HPP
#define EVENT_HPP


#include "window.hpp"




namespace ShishGL {

    class Window;

    struct Event {

        Window* target;
        int event_code;

    };

}

#endif //EVENT_HPP
