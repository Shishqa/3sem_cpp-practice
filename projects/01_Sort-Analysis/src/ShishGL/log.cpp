#include <cstdio>

#include "ShishGL/log.hpp"


FILE* ShishGL::LOG_FILE = nullptr;

bool ShishGL::do_log = false;


enum {
    LOG_SUCCESS = 1,
    LOG_FAILURE = 0
};


int ShishGL::openLog() {

    LOG_FILE = fopen(".ShishGL_log", "w");

    return (LOG_FILE ? LOG_SUCCESS : LOG_FAILURE);
}


int ShishGL::closeLog() {

    return fclose(LOG_FILE);
}


__attribute__((format(printf, 1, 2)))
int ShishGL::printLog(const char* format, ...) {
    if (do_log) {

        fprintf(LOG_FILE, "### ");

        va_list arg_list;
        va_start(arg_list, format);
        int res = fprintf(LOG_FILE, format, arg_list);
        va_end(arg_list);

        fprintf(LOG_FILE, "\n");

        return res;
    }
    return 0;
}
