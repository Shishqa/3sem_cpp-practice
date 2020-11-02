/*============================================================================*/
#include <fstream>
#include <iostream>
#include <cassert>
#include <sys/stat.h>

#include "ShishGL/text/text.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Text::Text(const std::string_view &filename, size_t n_bytes)
    : buffer(nullptr)
    , buffer_size(n_bytes) {

    std::ifstream input(filename.data());

    if (n_bytes == 0) {
        struct stat stat_buf = {};
        if (-1 == stat(filename.data(), &stat_buf)) {
            perror("stat");
            abort();
        }
        buffer_size = stat_buf.st_size;
    }

    assert(buffer_size != 0);

    buffer = new char[buffer_size];
    input.read(buffer, buffer_size);

    std::string_view buf_str(buffer, buffer_size);
    size_t curr_pos = 0;
    do {

        size_t line_end = buf_str.find('\n', curr_pos);

        if (line_end == std::string_view::npos) {
            text_lines.emplace_back(buf_str.substr(curr_pos, buf_str.size() - curr_pos));
            curr_pos = line_end;
        } else {
            text_lines.emplace_back(buf_str.substr(curr_pos, line_end - curr_pos));
            buffer[line_end] = '\0';
            curr_pos = line_end + 1;
        }

    } while (curr_pos != std::string_view::npos);

}

/*----------------------------------------------------------------------------*/

Text::~Text() {
    delete[] buffer;
}

/*============================================================================*/
