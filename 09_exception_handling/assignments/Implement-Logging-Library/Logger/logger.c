#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"

// Internal state
static FILE *global_log_file = NULL;
static log_level_t global_log_level = LOG_DEBUG; // default log level

// Map level to string
static const char *log_level_str(log_level_t level) {
    switch(level) {
        case LOG_EMERGENCY:  return "EMERGENCY";
        case LOG_ALERT:      return "ALERT";
        case LOG_CRITICAL:   return "CRITICAL";
        case LOG_ERROR:      return "ERROR";
        case LOG_WARNING:    return "WARNING";
        case LOG_NOTICE:     return "NOTICE";
        case LOG_INFO:       return "INFO";
        case LOG_DEBUG:      return "DEBUG";
        default:             return "UNKNOWN";
    }
}

int logger_init(const char *logfile_path, log_level_t initial_level) {
    global_log_level = initial_level;

    if (logfile_path) {
        global_log_file = fopen(logfile_path, "a");
        if (!global_log_file) {
            return -1; // failed to open file
        }
    }
    return 0;
}

void logger_set_level(log_level_t level) {
    global_log_level = level;
}

log_level_t logger_get_level(void) {
    return global_log_level;
}

void logger_close(void) {
    if (global_log_file) {
        fflush(global_log_file);
        fclose(global_log_file);
        global_log_file = NULL;
    }
}

void logger_log(log_level_t level, const char *file, int line, const char *format, ...) {
    // Only log messages with level <= global_log_level
    if (level > global_log_level) return;

    // Timestamp
    char time_str[32]; // enough for "YYYY-MM-DD HH:MM:SS" + '\0'
    time_t now = time(NULL);
    struct tm *tm_now;

    time(&now);
    tm_now = localtime(&now);

    if (strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_now) == 0) {
        // fallback
        strncpy(time_str, "0000-00-00 00:00:00", sizeof(time_str));
        time_str[sizeof(time_str) - 1] = '\0';
    }

    // Format the user message safely
    char msg_str[512];
    va_list ap;
    va_start(ap, format);
    vsnprintf(msg_str, sizeof(msg_str), format, ap);
    va_end(ap);

    // Compose final log line
    char line_str[1024];
    // [YYYY-MM-DD HH:MM:SS] [LEVEL] [FILENAME:LINE] - Message
    snprintf(line_str, sizeof(line_str), "[%s] [%s] [%s:%d] - %s\n",
            time_str, log_level_str(level), file ? file : "?", line, msg_str);

    // Write to console with errors and above -> stderr, others -> stdout
    FILE *console = (level <= LOG_ERROR) ? stderr : stdout;
    fputs(line_str, console);
    fflush(console);

    // File logging (optional)
    if (global_log_file) {
        fputs(line_str, global_log_file);
        fflush(global_log_file);
    }
}
