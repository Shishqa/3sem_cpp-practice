#ifndef APPLICATION_HPP
#define APPLICATION_HPP

void onRender();
void onReshape(int w, int h);
void onIdle();

void draw();

//#include <cstddef>
//#include <vector>
//
//class AppWindow {
//public:
//
//    AppWindow(const char* title);
//
//    void run();
//
//private:
//
//    static const size_t INIT_WINDOW_HEIGHT = 640, // px
//                        INIT_WINDOW_WIDTH  = 640, // px
//                        INIT_GAP           = 10;  // px
//
//    void onRender();
//
//    void onReshape(int width, int height);
//
//    void onKeyPress(unsigned char key, int x, int y);
//
//    void onMouseClick(int button, int state, int x, int y);
//};


#endif //APPLICATION_HPP
