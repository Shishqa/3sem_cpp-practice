#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <cstddef>
#include "window.hpp"
#include "colors.hpp"


namespace ShishGL {

    class Button : public Window {
    public:

        Button() = delete;

        Button(const char* button_label, const Event& click_event,
               const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height,
               const Color& default_color = {LEMON_CHIFFON, 255},
               const Color& hover_color   = {PAPAYA_WHIP,   255},
               const Color& click_color   = {WHITE,         255});

        ~Button() override = default;

    protected:

        Event on_click;

        const char* label;
        size_t label_len;

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
