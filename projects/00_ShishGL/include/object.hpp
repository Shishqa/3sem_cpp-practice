#ifndef OBJECT_HPP
#define OBJECT_HPP


namespace ShishGL {

    class EventBuffer;

    class Object {
    public:

        Object() = default;
        virtual ~Object() = default;

    protected:

        virtual bool getEvent(const Event*) { return false; }

        friend EventBuffer;
    };

}

#endif //OBJECT_HPP
