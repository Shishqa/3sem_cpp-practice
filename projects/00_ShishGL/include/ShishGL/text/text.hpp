/*============================================================================*/
#ifndef SHISHGL_TEXT_HPP
#define SHISHGL_TEXT_HPP
/*============================================================================*/
#include <string_view>
#include <vector>
/*============================================================================*/
namespace ShishGL {

    class Text {
    public:

        Text() = delete;

        explicit Text(const std::string_view& filename, size_t n_bytes = 0);

        virtual ~Text();

        [[nodiscard]]
        const std::vector<std::string_view>& lines() const { return text_lines; }

    protected:

        char* buffer;
        size_t buffer_size;

        std::vector<std::string_view> text_lines;

    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_HPP
/*============================================================================*/