#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <cstddef>
#include "window.hpp"


namespace ShishGL {

    class Button : public Window {
    public:

        Button() = delete;

        Button(const char* button_label,
               const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height,
               const Color& default_color, const Color& hover_color,
               const Color& click_color);

        virtual ~Button();

    protected:

        const char* label;
        int label_len;

        Color color_current,
              color_default,
              color_hover,
              color_click;

        void drawLabel();

        virtual void onRender() override;

        virtual void onEntry(int state) override;

        virtual void onMouseClick(int button, int state, int x, int y) override;

    };

}


#endif //BUTTON_HPP
