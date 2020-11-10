/*============================================================================*/
#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "ShishGL/core/input/timer.hpp"
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/core_application.hpp"
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

LogSystem::LogStatus LogSystem::printLog(const char *format, ...) {

    va_list arg_list = {};
    va_start(arg_list, format);
    print(CoreApplication::getRunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    flush();

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printWarning(const char *format, ...) {

    va_list arg_list = {};
    va_start(arg_list, format);
    print(CoreApplication::getRunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    flush();

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printError(const char *format, ...) {

    va_list arg_list = {};
    va_start(arg_list, format);
    print(CoreApplication::getRunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    flush();

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::print(const TimeDelta& elapsed,
                                      const char* format, va_list args) {

    static TimeDelta last_msg_begin = {};
    static TimeDelta last_msg_end = {};

    static char last_msg[4096] = "";
    static size_t last_msg_cnt = 0;

    static char buffer[4096] = "";

    size_t str_len = vsnprintf(buffer, sizeof(buffer), format, args);

    if (!strncmp(buffer, last_msg, str_len)) {

        last_msg_cnt++;
        last_msg_end = elapsed;

    } else {

        if (last_msg_cnt > 1) {

            fprintf(LOG_FILE, "[%15ld]\n"
                              "        |         : %s (x%lu)\n"
                              "[%15ld]\n",
                    last_msg_begin.count(),
                    last_msg, last_msg_cnt,
                    last_msg_end.count());

        } else if (last_msg_cnt == 1) {

            fprintf(LOG_FILE, "[%15ld] : %s\n",
                    last_msg_end.count(), last_msg);

        }

        strncpy(last_msg, buffer, str_len + 1);

        last_msg_cnt = 1;
        last_msg_begin = elapsed;
        last_msg_end = elapsed;

    }

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

void LogSystem::flush() {
    fflush(LOG_FILE);
}

/*============================================================================*/
