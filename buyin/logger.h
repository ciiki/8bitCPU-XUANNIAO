#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <cstdarg>
#include <cstdio>

#define BUYIN_PRINT(...) CompileLogger::Instance()->Print(__VA_ARGS__)

class CompileLogger {
public:
    static CompileLogger* Instance() {
        static CompileLogger instance;
        return &instance;
    }

    void Print(const char* format, ...) {
        bool is_print = true;
        if(is_print) {
            va_list args;    
            va_start(args, format);
            std::vprintf(format, args);
            va_end(args);
        }
    }
};
#endif // __LOGGER_H__