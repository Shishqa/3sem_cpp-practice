#ifndef LOG_HPP
#define LOG_HPP

namespace ShishGL {

    extern FILE* LOG_FILE;
    extern bool do_log;

    int openLog();

    template <typename... Args>
    int printLog(const char* format, Args... args) {
        if (do_log) {
            fprintf(LOG_FILE, "### ");
            return fprintf(LOG_FILE, format, args...);
        }
        return 0;
    }

    int closeLog();

}

#endif //LOG_HPP
