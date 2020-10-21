/*============================================================================*/
#ifndef SHISHGL_LOG_HPP
#define SHISHGL_LOG_HPP
/*============================================================================*/

#include <cstdio>

/*============================================================================*/

namespace ShishGL {

    class LogSystem {
    public:

        LogSystem() = delete;

        virtual ~LogSystem() = default;

        typedef enum {
            LOG_OK = 0,
            LOG_OPEN_ERR,
            LOG_ALREADY_OPENED,
            LOG_CLOSE_ERR,
            LOG_FILE_BROKEN,
            LOG_PRINT_ERR
        } LogStatus;

        static LogStatus printLog(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

    private:

        static LogStatus openLog();

        static LogStatus closeLog();

        static FILE* LOG_FILE;

        template <typename GraphicEngine, typename WindowEngine>
        friend class GEngine;
    };
}

/*============================================================================*/
#endif //SHISHGL_LOG_HPP
/*============================================================================*/
