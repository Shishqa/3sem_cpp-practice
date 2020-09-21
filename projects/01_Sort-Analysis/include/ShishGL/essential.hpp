#ifndef ESSENTIAL_HPP
#define ESSENTIAL_HPP


namespace ShishGL {

    template <typename T>
    struct Vector2 {
        T x, y;
    };

    int init(int* argc_ptr, char** argv);

    int enterMainLoop();

    void terminate();

}


#endif //ESSENTIAL_HPP
