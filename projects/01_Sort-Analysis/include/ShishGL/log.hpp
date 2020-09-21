#ifndef LOG_HPP
#define LOG_HPP


#include <cstddef>


namespace ShishGL {

    int openLog();

    int printLog(const char* format, ...) __attribute__((format(printf, 1, 2)));

    int closeLog();

}

#endif //LOG_HPP
