#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

// Log levels (0 = most severe, 7 = least severe)
typedef enum {
    LOG_EMERGENCY,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
}log_level_t;

// Initialize logger. If logfile_path is NULL logging to file is disabled.
// initial_level sets the minimum (highest numeric allowed) level to log.
// Return 0 on success, non-zero on failure to open file.
int logger_init(const char *logfile_path, log_level_t initial_level);

// Change runtime level
void logger_set_level(log_level_t level);

// Get current level
log_level_t logger_get_level(void);

// Close logger and free resources
void logger_close(void);

// Core logging function
void logger_log(log_level_t level, const char *file, int line, const char *format, ...);

// Macro automatically fills __FILE__ and __LINE__
// Usage example: log_message(LOG_ERROR, "Failed to open: %s", path);
#define log_message(level, format, ...) \
    logger_log((level), __FILE__, __LINE__, (format), ##__VA_ARGS__)

#endif //LOGGER_H