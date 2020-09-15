#include <cstdio>

#include "log.hpp"


FILE* ShishGL::LOG_FILE = nullptr;

bool ShishGL::do_log = false;


enum {
    LOG_SUCCESS = 0,
    LOG_FAILURE = 1
};


int ShishGL::openLog() {

    LOG_FILE = fopen(".ShishGL_log", "w");

    return (LOG_FILE ? LOG_SUCCESS : LOG_FAILURE);
}


int ShishGL::closeLog() {

    return fclose(LOG_FILE);
}
