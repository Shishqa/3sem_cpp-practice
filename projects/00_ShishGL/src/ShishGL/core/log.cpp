/*============================================================================*/
#include <cstdio>
#include <cstdarg>
#include <chrono>

#include "ShishGL/core/log.hpp"
#include "ShishGL/core/core_application.hpp"
/*============================================================================*/
using namespace ShishGL;
using namespace std::chrono;
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

LogSystem::LogStatus LogSystem::print(const char* format, ...) {

    high_resolution_clock::time_point now = high_resolution_clock::now();
    duration<double, std::milli> delta_time = now - CoreApplication::getInitTime();

    fprintf(LOG_FILE, "[%6.3lf] : ", delta_time.count());

    va_list arg_list = {};
    va_start(arg_list, format);
    vfprintf(LOG_FILE, format, arg_list);
    va_end(arg_list);

    fprintf(LOG_FILE, "\n");
    flush();

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printLog(const char *format, ...) {
    fprintf(LOG_FILE, "%s ", "<OK> ");

    va_list arg_list = {};
    va_start(arg_list, format);
    print(format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printError(const char *format, ...) {
    fprintf(LOG_FILE, "%s ", "<EE> ");

    va_list arg_list = {};
    va_start(arg_list, format);
    print(format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printWarning(const char *format, ...) {
    fprintf(LOG_FILE, "%s ", "<WW> ");

    va_list arg_list = {};
    va_start(arg_list, format);
    print(format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

void LogSystem::flush() {
    fflush(LOG_FILE);
}

/*============================================================================*/
