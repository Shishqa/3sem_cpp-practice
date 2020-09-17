#ifndef LOG_HPP
#define LOG_HPP


#include <cstdio>
#include <cstdarg>


namespace ShishGL {

    extern FILE* LOG_FILE;
    extern bool do_log;

    int openLog();


    int printLog(const char* format, ...) __attribute__((format(printf, 1, 2)));


    int closeLog();

}

#endif //LOG_HPP
