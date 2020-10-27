/*============================================================================*/
#include <cstdio>
#include <cstdarg>
#include <ctime>

#include "ShishGL/log.hpp"
#include "ShishGL/engine.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

FILE* LogSystem::LOG_FILE = nullptr;

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::openLog() {
    if (LOG_FILE) {
        return LOG_ALREADY_OPENED;
    }
    LOG_FILE = fopen(".ShishGL_log", "w");
    return (LOG_FILE ? LOG_OK : LOG_OPEN_ERR);
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::closeLog() {
    fclose(LOG_FILE);
    LOG_FILE = nullptr;
    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

// TODO: add urgency!
LogSystem::LogStatus LogSystem::printLog(const char* format, ...) {

    time_t now = time(nullptr);
    double time_diff = difftime(now, Engine::getInitTime());

    fprintf(LOG_FILE, "[%lf]\t", time_diff);

    va_list arg_list = {};
    va_start(arg_list, format);
    vfprintf(LOG_FILE, format, arg_list);
    va_end(arg_list);

    fprintf(LOG_FILE, "\n");
    flush();

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

void LogSystem::flush() {
    fflush(LOG_FILE);
}

/*============================================================================*/
