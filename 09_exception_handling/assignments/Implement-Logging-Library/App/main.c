#include "../Logger/logger.h"
#include <stdlib.h>

int main (void) {
    // Initialize logger: write to "app_log.txt", start at INFO (so DEBUG will be ignored)
    if (logger_init("app_log.txt", LOG_INFO) != 0) {
        fprintf(stderr, "Failed to open log file, continuing without file logging\n");
    }

    // Example usage scenarios
    log_message(LOG_EMERGENCY, "System is crashing");
    log_message(LOG_ALERT, "Detect %s in the system", "overheat");
    log_message(LOG_CRITICAL, "Detect failure in module %s", "sensor");
    log_message(LOG_ERROR, "Permission denied when open file: %d", -1);
    log_message(LOG_WARNING, "Low storage space: %d MB", 512);
    log_message(LOG_NOTICE, "Led %d ON", 2);
    log_message(LOG_INFO, "Initialize successfully");
    log_message(LOG_DEBUG, "This message should not appear with current log level LOG_INFO");

    // Change log level to DEBUG during runtime
    logger_set_level(LOG_DEBUG);
    log_message(LOG_DEBUG, "Debug is now enabled");

    // Disable file logging
    logger_close();

    //  Switch to console only by passing NULL file path
    logger_init(NULL, LOG_INFO); // init with INFO level
    log_message(LOG_INFO, "Logging to console only now");

    logger_close();
    return 0;
}