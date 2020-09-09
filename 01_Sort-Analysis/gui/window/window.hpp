#ifndef WINDOW_HPP
#define WINDOW_HPP


class Window {
public:

    Window();

    explicit Window(const char* title,
                    int pos_x, int pos_y,
                    int width, int height);

private:

    virtual void onRender() = 0;

    virtual void onReshape(int width, int height) = 0;

    virtual void onKeyPress(unsigned char key, int x, int y) = 0;

    virtual void onMouseClick(int button, int state, int x, int y) = 0;

    int id;
};


#endif //WINDOW_HPP
