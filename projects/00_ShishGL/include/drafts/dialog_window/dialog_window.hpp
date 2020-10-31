/*============================================================================*/
#ifndef SHISHGL_DIALOG_WINDOW_HPP
#define SHISHGL_DIALOG_WINDOW_HPP
/*============================================================================*/
#include "../../ShishGL/window.hpp"
/*============================================================================*/
namespace ShishGL {

    struct DialogWindowColors {
        ButtonColorScheme border;
        ButtonColorScheme close;
    };

    static constexpr DialogWindowColors DEFAULT_DIALOG_COLORS = {
            {DARK_BLUE, LIGHT_BLUE, WHITE},
            {SALMON, LIGHT_SALMON, PAPAYA_WHIP}
    };

    static constexpr size_t DIALOG_HEADER_SIZE = 30;
    static constexpr size_t DIALOG_BORDER_SIZE = 10;

    class DialogWindow : public RectFloat {
    public:

        DialogWindow() = delete;



        ~DialogWindow() override = default;

    protected:

        RectWindow* content;

        friend class CoreApplication;

        template <typename ContentWindow, typename... Args>
        explicit DialogWindow(const Vector2<int>& pos,
                              const Vector2<size_t>& size,
                              const DialogWindowColors& colors,
                              Args&&... args)
                : RectFloat(nullptr, colors.border, pos, size) {

            Vector2<int> content_pos{
                    DIALOG_BORDER_SIZE, DIALOG_HEADER_SIZE
            };

            /* TODO: fix very small size overflow */
            Vector2<size_t> content_size{
                    size.x - 2 * DIALOG_BORDER_SIZE,
                    size.y - DIALOG_HEADER_SIZE + DIALOG_BORDER_SIZE
            };

            content = attach<ContentWindow>(content_pos, content_size,
                                            std::forward<Args>(args)...);
        }

        bool filterEvent(const Event* event) override {

            if (event->type() == Event::MOUSE_MOVE ||
                event->type() == Event::MOUSE_BUTTON) {

                auto mouse = dynamic_cast<const MouseEvent*>(event);
                if (!mouse) {
                    return false;
                }

                if (content->contains(mouse->where())) {
                    return false;
                }

            }

            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_DIALOG_WINDOW_HPP
/*============================================================================*/
