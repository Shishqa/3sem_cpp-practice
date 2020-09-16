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
            int fprintf_ret = fprintf(LOG_FILE, format, args...);
            fprintf(LOG_FILE, "\n");
            return fprintf_ret;
        }
        return 0;
    }

    int closeLog();

}

#endif //LOG_HPP
